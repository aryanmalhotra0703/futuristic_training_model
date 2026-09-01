class Solution {
public:
    int minCostConnectPoints(vector<vector<int>>& points) {
        int n=points.size();
        vector<vector<pair<int,int>>>edges(n);
        for(int i=0;i<n-1;i++){
            for(int j=i+1;j<n;j++){
                int dis=abs(points[i][0]-points[j][0])+abs(points[i][1]-points[j][1]);
                edges[i].push_back({dis,j});
                edges[j].push_back({dis,i});
            }
        }
        int minCost=0;
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
        vector<bool>vis(n,false);
        pq.push({0,0});
        while(!pq.empty()){
            int wt=pq.top().first;
            int node=pq.top().second;
            pq.pop();
            if(!vis[node]){
                vis[node]=true;
                minCost+=wt;
                for(auto it:edges[node]){
                    int neigh=it.second;
                    int edgeW=it.first;
                    if(!vis[neigh]){
                        pq.push({edgeW,neigh});
                    }
                }
            }
        }
        return minCost;        
    }
};