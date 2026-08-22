class Solution {
public:

bool dfs(int curr, vector<bool>&vis, vector<bool>& recPath, vector<vector<int>>& prerequisites){
    vis[curr]=true;
    recPath[curr]=true;
    for(int i=0;i<prerequisites.size();i++){
        if(prerequisites[i][0]==curr){
            if(!vis[prerequisites[i][1]]){
                if(dfs(prerequisites[i][1],vis,recPath,prerequisites)){
                    return true;
                }
            }
            else if(recPath[prerequisites[i][1]]){
                return true;
            }
        }
    }
    recPath[curr]=false;
    return false;
}
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<bool>vis(numCourses,false);
        vector<bool>recPath(numCourses,false);
        for(int i=0;i<numCourses;i++){
            if(!vis[i]){
                if(dfs(i,vis,recPath,prerequisites)){
                    return false;
                }
            }
        }
        return true;
    }
};