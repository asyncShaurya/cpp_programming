#include <bits/stdc++.h>
using namespace std;

using VI = vector<int>;
using VVI = vector<VI>;
using pii = pair<int,int>;

int maxCyclesEnumerated = 2000; 


vector<int> neighborsSignature(const unordered_map<int, vector<int>> &adj, int node) {
    auto it = adj.find(node);
    if (it == adj.end()) return {};
    vector<int> s = it->second;
    sort(s.begin(), s.end());
    return s;
}

bool findIsomorphism(
    const unordered_map<int, vector<int>>& A,
    const unordered_map<int, vector<int>>& B,
    unordered_map<int,int>& mapping
) {
    
    vector<int> nodesA, nodesB;
    for (auto &p: A) nodesA.push_back(p.first);
    for (auto &p: B) nodesB.push_back(p.first);
    if (nodesA.size() != nodesB.size()) return false;
    int n = nodesA.size();

    
    unordered_map<int,int> idxA, idxB;
    for (int i=0;i<n;i++) idxA[nodesA[i]] = i;
    for (int i=0;i<n;i++) idxB[nodesB[i]] = i;


    vector<vector<char>> matA(n, vector<char>(n,0)), matB(n, vector<char>(n,0));
    for (int i=0;i<n;i++){
        int u = nodesA[i];
        for (int v: A.at(u)) matA[i][ idxA[v] ] = 1;
    }
    for (int i=0;i<n;i++){
        int u = nodesB[i];
        for (int v: B.at(u)) matB[i][ idxB[v] ] = 1;
    }

    
    vector<int> degA(n), degB(n);
    for (int i=0;i<n;i++){
        degA[i] = (int)A.at(nodesA[i]).size();
        degB[i] = (int)B.at(nodesB[i]).size();
    }

    
    vector<vector<int>> candidates(n);
    for (int i=0;i<n;i++){
        for (int j=0;j<n;j++){
            if (degA[i] == degB[j]) candidates[i].push_back(j);
        }
        if (candidates[i].empty()) return false; 
    }

    vector<int> mapAtoB(n, -1), mapBtoA(n, -1);
    vector<char> usedB(n,0);
    vector<int> order(n);
    iota(order.begin(), order.end(), 0);
    sort(order.begin(), order.end(), [&](int i, int j){
        return candidates[i].size() < candidates[j].size();
    });

    function<bool(int)> backtrack = [&](int pos)->bool{
        if (pos == n) return true;
        int ia = order[pos];
        for (int jb : candidates[ia]) {
            if (usedB[jb]) continue;
            bool ok = true;
            for (int ka = 0; ka < n; ++ka) {
                if (mapAtoB[ka] == -1) continue;
                if (matA[ia][ka]) {
                    if (!matB[jb][ mapAtoB[ka] ]) { ok = false; break; }
                }
                if (matA[ka][ia]) {
                    if (!matB[ mapAtoB[ka] ][jb]) { ok = false; break; }
                }
            }
            if (!ok) continue;


            mapAtoB[ia] = jb;
            mapBtoA[jb] = ia;
            usedB[jb] = 1;
            if (backtrack(pos+1)) return true;

            mapAtoB[ia] = -1;
            mapBtoA[jb] = -1;
            usedB[jb] = 0;
        }
        return false;
    };

    bool found = backtrack(0);
    if (!found) return false;
    mapping.clear();
    for (int i=0;i<n;i++){
        int aNode = nodesA[i];
        int bNode = nodesB[ mapAtoB[i] ];
        mapping[aNode] = bNode;
    }
    return true;
}

void enumerateSimpleCycles(const unordered_map<int, vector<int>>& adj,
                           vector<vector<int>>& cycles,
                           int cap = 2000) {
    vector<int> nodes;
    for (auto &p : adj) nodes.push_back(p.first);
    sort(nodes.begin(), nodes.end());
    unordered_map<int,int> idx;
    for (int i=0;i<(int)nodes.size();++i) idx[nodes[i]] = i;

    int n = nodes.size();
    vector<int> stack;
    vector<char> blocked(n,0);
    vector<char> onStackVal(n,0);
    function<void(int,int)> dfs = [&](int start, int uIdx){
        onStackVal[uIdx]=1;
        stack.push_back(nodes[uIdx]);
        for (int v : adj.at(nodes[uIdx])) {
            int vIdx = idx[v];
            if (vIdx < start) continue; 
            if (vIdx == start && stack.size() >= 2) {
                cycles.push_back(stack);
                if ((int)cycles.size() >= cap) return;
            } else if (!onStackVal[vIdx]) {
                dfs(start, vIdx);
                if ((int)cycles.size() >= cap) return;
            }
            if ((int)cycles.size() >= cap) return;
        }
        onStackVal[uIdx]=0;
        stack.pop_back();
    };

    for (int s=0;s<n && (int)cycles.size()<cap; ++s) {
        fill(onStackVal.begin(), onStackVal.end(), 0);
        stack.clear();
        dfs(s, s);
    }

    set<vector<int>> uniq;
    vector<vector<int>> finalCycles;
    for (auto &c : cycles) {
        
        int m = c.size();
        int posMin = 0;
        for (int i=1;i<m;i++) if (c[i] < c[posMin]) posMin = i;
        vector<int> r(m);
        for (int i=0;i<m;i++) r[i] = c[(posMin + i)%m];
        
        vector<int> rev(m);
        for (int i=0;i<m;i++) rev[i] = r[(m-i)%m];
        vector<int> canon = min(r, rev);
        if (!uniq.count(canon)) {
            uniq.insert(canon);
            finalCycles.push_back(canon);
        }
    }
    cycles.swap(finalCycles);
}


int minimalRotationsBFS(
    const vector<int>& cycleNodes, 
    const vector<vector<int>>& cycles, 
    const unordered_map<int,int>& permMapping 
) {
    int u = cycleNodes.size();
    if (u == 0) return 0;

    unordered_map<int,int> pos;
    for (int i=0;i<u;i++) pos[cycleNodes[i]] = i;

    unordered_map<int,int> labelIndex;
    for (int i=0;i<u;i++) labelIndex[ cycleNodes[i] ] = i;

    vector<int> startState(u), targetState(u);
    for (int i=0;i<u;i++) {
        startState[i] = labelIndex[ cycleNodes[i] ]; 
        int targetNode = permMapping.at(cycleNodes[i]);
        if (!labelIndex.count(targetNode)) {
            return -1;
        }
        targetState[i] = labelIndex[targetNode];
    }

    if (startState == targetState) return 0;

    
    vector<vector<int>> cyclesPos;
    for (auto &c : cycles) {
        vector<int> v;
        for (int node : c) {
            if (!pos.count(node)) { v.clear(); break; }
            v.push_back(pos[node]);
        }
        if (!v.empty()) cyclesPos.push_back(v);
    }
    if (cyclesPos.empty()) return -1;

    
    auto pack = [&](const vector<int>& s)->string{
        string key;
        key.resize(u);
        for (int i=0;i<u;i++){
            key[i] = char(s[i] + 1);
        }
        return key;
    };

    string targetKey = pack(targetState);
    string startKey = pack(startState);

    unordered_map<string,int> dist;
    queue<string> q;
    dist[startKey] = 0;
    q.push(startKey);

    while(!q.empty()){
        string cur = q.front(); q.pop();
        int d = dist[cur];
        vector<int> arr(u);
        for (int i=0;i<u;i++) arr[i] = int(cur[i]) - 1;
        
        for (auto &cp : cyclesPos) {
            int m = cp.size();
        
            vector<int> nxt = arr;
            for (int i=0;i<m;i++){
                nxt[ cp[(i+1)%m] ] = arr[ cp[i] ];
            }
            string nk = pack(nxt);
            if (!dist.count(nk)) {
                dist[nk] = d+1;
                if (nk == targetKey) return d+1;
                q.push(nk);
            }
        }
    }

    return -1;
}


int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int E;
    if (!(cin >> E)) return 0;
    vector<pair<int,int>> edgesCur(E), edgesExp(E);
    for (int i=0;i<E;i++){
        int a,b; cin>>a>>b;
        edgesCur[i] = {a,b};
    }
    for (int i=0;i<E;i++){
        int a,b; cin>>a>>b;
        edgesExp[i] = {a,b};
    }

    
    unordered_map<int, vector<int>> adjCur, adjExp;
    auto addEdge = [&](unordered_map<int, vector<int>>& adj, pair<int,int> e){
        adj[e.first].push_back(e.second);
        adj[e.second].push_back(e.first);
    };
    for (auto &e: edgesCur) addEdge(adjCur, e);
    for (auto &e: edgesExp) addEdge(adjExp, e);

    
    set<int> nodesCurSet, nodesExpSet;
    for (auto &p: adjCur) nodesCurSet.insert(p.first);
    for (auto &p: adjExp) nodesExpSet.insert(p.first);
    if (nodesCurSet.size() != nodesExpSet.size()) {
        cout << -1 << "\n";
        return 0;
    }

    unordered_map<int,int> mapping;
    bool okIso = findIsomorphism(adjCur, adjExp, mapping);
    if (!okIso) {
        cout << -1 << "\n";
        return 0;
    }

    
    vector<vector<int>> cycles;
    enumerateSimpleCycles(adjCur, cycles, maxCyclesEnumerated);

    
    set<int> cycleNodeSet;
    for (auto &c : cycles) for (int v : c) cycleNodeSet.insert(v);
    vector<int> cycleNodesVec(cycleNodeSet.begin(), cycleNodeSet.end());

    
    for (auto &p : adjCur) {
        int node = p.first;
        if (!cycleNodeSet.count(node)) {
            if (mapping[node] != node) {
                cout << -1 << "\n";
                return 0;
            }
        }
    }

    
    int ans = minimalRotationsBFS(cycleNodesVec, cycles, mapping);
    cout << ans << "\n";
    return 0;
}
