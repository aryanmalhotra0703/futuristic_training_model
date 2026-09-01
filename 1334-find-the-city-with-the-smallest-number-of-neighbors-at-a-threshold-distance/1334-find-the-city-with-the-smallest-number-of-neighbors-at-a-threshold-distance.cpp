class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        vector<vector<pair<int,int>>>adj(n);
        for(int i=0;i<edges.size();i++){
            adj[edges[i][0]].push_back({edges[i][1],edges[i][2]});
            adj[edges[i][1]].push_back({edges[i][0],edges[i][2]});
        }
        int INF=1e9;
        vector<vector<int>>dis(n,vector<int>(n,INF));
        for(int i=0;i<n;i++){
            dis[i][i]=0;
        }

        for(int i=0;i<n;i++){
            for(auto [neigh,weight]:adj[i]){
                dis[i][neigh]=weight;
            }
        }
        for(int k=0;k<n;k++){
            for(int i=0;i<n;i++){
                for(int j=0;j<n;j++){
                    dis[i][j]=min(dis[i][j],dis[i][k]+dis[k][j]);
                }
            }
        }
        int ans=-1;
        int mini=INT_MAX;
        for(int i=0;i<n;i++){
            int count=0;
            for(int j=0;j<n;j++){
                if(i!=j && dis[i][j]<=distanceThreshold){
                    count++;
                }
            }
            if(count<=mini){
                mini=count;
                ans=i;
            }
        }
        return ans;
    }
};