#include<bits/stdc++.h>
using namespace std;

class DisjointSet {
private:
    vector<int> rank, parent, size;
public:
    DisjointSet(int n) {
        rank.resize(n + 1, 0);
        size.resize(n + 1, 1);
        parent.resize(n + 1);
        for (int i = 0; i <= n; i++) parent[i] = i;
    }

    int findUPar(int node) {
        if (node == parent[node]) return node;
        return parent[node] = findUPar(parent[node]);
    }

    void unionByRank(int u, int v) {
        int ulp_u = findUPar(u);
        int ulp_v = findUPar(v);
        if (ulp_u == ulp_v) return;
        if (rank[ulp_u] < rank[ulp_v]) {
            parent[ulp_u] = ulp_v;
        } else if (rank[ulp_v] < rank[ulp_u]) {
            parent[ulp_v] = ulp_u;
        } else {
            parent[ulp_v] = ulp_u;
            rank[ulp_u]++;
        }
    }
};

class Solution {
public:
    int spanningTree(int V, vector<vector<pair<int,int>>>& adj) {
        vector<pair<int, pair<int, int>>> edges;

        for (int i = 0; i < V; i++) {
            for (auto it : adj[i]) {
                int adjNode = it.first;
                int wt = it.second;
                int node = i;
                if (node < adjNode)  
                    edges.push_back({wt, {node, adjNode}});
            }
        }

        sort(edges.begin(), edges.end());
        DisjointSet ds(V);
        int ans = 0;

        for (auto it : edges) {
            int wt = it.first;
            int u = it.second.first;
            int v = it.second.second;
            if (ds.findUPar(u) != ds.findUPar(v)) {
                ans += wt;
                ds.unionByRank(u, v);
            }
        }

        return ans;
    }
};

int main() {
    int V = 5;
    vector<vector<int>> edges = {
        {0,1,3},
        {0,2,1},
        {1,2,1},
        {2,3,2},
        {3,4,1},
        {4,2,2}
    };

    vector<vector<pair<int, int>>> adj(V); 

    for (auto it : edges) {
        int u = it[0], v = it[1], w = it[2];
        adj[u].push_back({v, w});
        adj[v].push_back({u, w}); 
    }

    Solution obj;
    int mstWt = obj.spanningTree(V, adj);
    cout << "The sum of all edges weights: " << mstWt << endl;

    return 0;
}
