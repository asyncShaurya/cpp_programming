#include <iostream>
#include <vector>
#include <set>
#include <string>
using namespace std;

struct Band {
    set<pair<int,int>> cells; // occupied cells
    vector<pair<int,int>> path; // full path in order
};

pair<int,int> move(char dir, int x, int y) {
    if(dir == 'u') return {x-1, y};
    if(dir == 'd') return {x+1, y};
    if(dir == 'l') return {x, y-1};
    if(dir == 'r') return {x, y+1};
    return {x, y};
}

Band make_band(int sx, int sy, const string& seq, int S) {
    Band band;
    int x = sx, y = sy;
    band.cells.insert({x, y});
    band.path.push_back({x, y});
    for(char dir : seq) {
        pair<int,int> nxt = move(dir, x, y);
        x = nxt.first;
        y = nxt.second;
        if(x < 0 || x >= S || y < 0 || y >= S) break; // out of bounds
        band.cells.insert({x, y});
        band.path.push_back({x, y});
    }
    return band;
}

bool is_interlocked(const Band& b1, const Band& b2) {

    // Build overlap map
    set<pair<int,int>> inter;
    for(auto& cell : b1.cells) {
        if(b2.cells.count(cell)) inter.insert(cell);
    }

    // If no overlap at all, they’re not interlocked, thus separable
    if(inter.empty()) return false;

    vector<int> idx1, idx2;
    for(int i=0; i < b1.path.size(); ++i)
        if(inter.count(b1.path[i]))
            idx1.push_back(i);

    for(int i=0; i < b2.path.size(); ++i)
        if(inter.count(b2.path[i]))
            idx2.push_back(i);

    // Check for alternation
    bool alternates = false;
    for(size_t i=1; i<inter.size(); ++i)
        if(idx1[i] < idx1[i-1] || idx2[i] < idx2[i-1])
            alternates = true;
    return alternates;
}

int main() {
    int S;
    cin >> S;
    int sx1, sy1, sx2, sy2;
    cin >> sx1 >> sy1;
    string seq1;
    cin >> seq1;
    cin >> sx2 >> sy2;
    string seq2;
    cin >> seq2;

    Band b1 = make_band(sx1, sy1, seq1, S);
    Band b2 = make_band(sx2, sy2, seq2, S);

    // Check interlocked
    if(is_interlocked(b1, b2)) {
        cout << "Impossible" << endl;
        return 0;
    }

    // Count overlap cells
    int overlap = 0;
    for(auto& cell : b1.cells)
        if(b2.cells.count(cell))
            ++overlap;
    cout << overlap << endl;
    return 0;
}