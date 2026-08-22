class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n=grid.size();
        if(grid[0][0]==1 || grid[n-1][n-1]==1){
            return -1;
        }
        vector<vector<bool>>vis(n,vector<bool>(n,false));
        queue<pair<pair<int,int>,int>>q;
        q.push({{0,0},1});
        vis[0][0]=true;
        int dr[] = {-1, -1, -1, 0, 0, 1, 1, 1};
        int dc[] = {-1, 0, 1, -1, 1, -1, 0, 1};
        while(!q.empty()) {
            int i=q.front().first.first;
            int j=q.front().first.second;
            int len=q.front().second;
            q.pop();
            if (i==n-1 && j==n-1){
                return len;
            }
            for(int k=0;k<8;k++) {
                int ni = i + dr[k];
                int nj = j + dc[k];
                if (ni >= 0 && ni < n && nj >= 0 && nj < n && grid[ni][nj] == 0 && !vis[ni][nj]) {
                    vis[ni][nj] = true;
                    q.push({{ni, nj}, len + 1});
                }
            }
        }
        return -1;
    }
};