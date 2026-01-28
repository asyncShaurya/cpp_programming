#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <string>
#include <algorithm>
using namespace std;

int stringWorth(const string &s) {
    int worth = 0;
    for (char c : s) {
        worth += (c - 'a' + 1);
    }
    return worth;
}

int main() {
    int N, M;
    cin >> N >> M;
    vector<string> strings(N);
    for (int i = 0; i < N; ++i)
        cin >> strings[i];
    
    vector<int> cost(N);
    for (int i = 0; i < N; ++i)
        cin >> cost[i];
    
    unordered_map<string, int> index;
    for (int i = 0; i < N; ++i)
        index[strings[i]] = i;
    
    // Contradictory pairs tracking
    vector<unordered_set<int>> contradict(N);
    for (int i = 0; i < M; ++i) {
        string a, b;
        cin >> a >> b;
        int ia = index[a], ib = index[b];
        contradict[ia].insert(ib);
        contradict[ib].insert(ia);
    }
    
    int budget;
    cin >> budget;
    vector<int> worth(N);
    for (int i = 0; i < N; ++i)
        worth[i] = stringWorth(strings[i]);
    
    int maxWorth = 0;
    // Try all subsets (bitmask)
    int total = 1 << N;
    for (int mask = 0; mask < total; ++mask) {
        int sumCost = 0;
        int sumWorth = 0;
        bool valid = true;
        // Check contradictions
        for (int i = 0; i < N && valid; ++i) {
            if (mask & (1 << i)) {
                sumCost += cost[i];
                sumWorth += worth[i];
                for (int c : contradict[i]) {
                    if (mask & (1 << c)) {
                        valid = false;
                        break;
                    }
                }
            }
        }
        if (valid && sumCost <= budget) {
            maxWorth = max(maxWorth, sumWorth);
        }
    }
    cout << maxWorth << endl;
    return 0;
}
