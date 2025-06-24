#include <bits/stdc++.h>
#include<vector>
#include<stack>
using namespace std;

class Solution {
private:
    bool knows(vector<vector<int>>& mat, int a, int b) {
        return mat[a][b] == 1;
    }

public:
    int celebrity(vector<vector<int>>& mat) {
        int n = mat.size();
        stack<int> s;

        
        for (int i = 0; i < n; i++) {
            s.push(i);
        }

        
        while (s.size() > 1) {
            int a = s.top(); s.pop();
            int b = s.top(); s.pop();

            if (knows(mat, a, b)) {
                s.push(b);  
            } else {
                s.push(a);
            }
        }

        if (s.empty()) return -1; 

        int candidate = s.top();

        // Verify: candidate knows no one (row must be 0s, excluding self)
        for (int i = 0; i < n; i++) {
            if (i != candidate && mat[candidate][i] != 0) {
                return -1;
            }
        }

        // Verify: everyone knows candidate (column must be 1s, excluding self)
        for (int i = 0; i < n; i++) {
            if (i != candidate && mat[i][candidate] != 1) {
                return -1;
            }
        }

        return candidate;
    }
};
