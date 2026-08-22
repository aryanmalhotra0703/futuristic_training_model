class Solution {
public:

    int find(int x, vector<int>& parent) {
        if(parent[x] == x)
            return x;

        return parent[x] = find(parent[x], parent);
    }

    void unite(int u, int v, vector<int>& parent, vector<int>& rank) {
        u = find(u, parent);
        v = find(v, parent);

        if(u == v)
            return;

        if(rank[u] < rank[v])
            parent[u] = v;
        else if(rank[u] > rank[v])
            parent[v] = u;
        else {
            parent[v] = u;
            rank[u]++;
        }
    }

    vector<int> findRedundantConnection(vector<vector<int>>& edges) {

        int n = edges.size();

        vector<int> parent(n + 1);
        vector<int> rank(n + 1, 0);

        for(int i = 1; i <= n; i++)
            parent[i] = i;

        for(auto edge : edges) {

            int u = edge[0];
            int v = edge[1];

            if(find(u, parent) == find(v, parent))
                return edge;

            unite(u, v, parent, rank);
        }

        return {};
    }
};