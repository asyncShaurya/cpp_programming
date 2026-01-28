#include <iostream>
#include <vector>
#include <string>
#include <tuple>
using namespace std;

struct Instruction {
    string turn;
    int dist;
};

pair<int,int> move(int x, int y, int dir, int dist) {
    static int dx[4] = {0, 1, 0, -1};
    static int dy[4] = {1, 0, -1, 0};
    return {x + dx[dir]*dist, y + dy[dir]*dist};
}

int turnDir(int dir, string turn) {
    if (turn == "left") return (dir+1)%4;
    if (turn == "right") return (dir+3)%4;
    if (turn == "straight") return dir;
    if (turn == "back") return (dir+2)%4;
    return dir;
}

string oppositeTurn(string turn) {
    if (turn == "left") return "right";
    if (turn == "right") return "left";
    if (turn == "straight") return "back";
    if (turn == "back") return "straight";
    return turn;
}

vector<string> turns = {"left", "right", "straight", "back"};

int main() {
    int N;
    cin >> N;
    vector<Instruction> instr(N);
    for (int i = 0; i < N; ++i)
        cin >> instr[i].turn >> instr[i].dist;
    int ax, ay, rx, ry;
    cin >> ax >> ay >> rx >> ry;

    // Simulate original path
    int x=ax, y=ay, dir=0;
    for (int i=0;i<N;++i) {
        dir = turnDir(dir, instr[i].turn);
        tie(x, y) = move(x, y, dir, instr[i].dist);
    }
    // If already matches Rabin's, output 'No'
    if (x == rx && y == ry) {
        cout << "No" << endl;
        return 0;
    }
    // changing each turn to all other possible turns
    for (int i=0;i<N;++i) {
        for (string t2 : turns) {
            if (t2 == instr[i].turn) continue;
            int x1=ax, y1=ay, d1=0;
            for (int j=0;j<N;++j) {
                string t = instr[j].turn;
                if (i == j) t = t2;
                d1 = turnDir(d1, t);
                tie(x1, y1) = move(x1, y1, d1, instr[j].dist);
            }
            if (x1 == rx && y1 == ry) {
                cout << "Yes" << endl;
                cout << instr[i].turn << " " << instr[i].dist << endl;
                cout << t2 << " " << instr[i].dist << endl;
                return 0;
            }
        }
    }
    cout << "No" << endl;
    return 0;
}
