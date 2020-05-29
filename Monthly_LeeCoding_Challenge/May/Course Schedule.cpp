class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& edgeList) {
        // finding cycle using color method
        //not visited = 0; visiting = 1; completed = 2
        if (numCourses<=1)
            return true;
        
        if(edgeList.size()==0) return true;
        
        int visited[numCourses];
        memset(visited, 0, sizeof(visited));
                
        //making adj list
        vector<int> adj[numCourses];
        for(int i=0; i<edgeList.size();i++){
            adj[edgeList[i][1]].push_back(edgeList[i][0]);
        } 
        
        bool ans=true;
        
        for(int i=0;i<numCourses;i++){
            if(visited[i]==0 ) // not visited
                ans = ans & dfs(i, -1, adj, visited);
            if(ans==false) break;
        }
        
        return ans;
    }
    
    
    bool dfs(int curr, int p, vector<int> adj[], int visited[] ){
        visited[curr]=1;
        
        for(auto i: adj[curr]){
            if(visited[i]==0){ //not visited
                dfs(i, curr, adj, visited);
            }
            if(visited[i]==1){ //visiting
                return false;
            }
        }
        visited[curr]=2; //completed
        
        return true;
    }
};