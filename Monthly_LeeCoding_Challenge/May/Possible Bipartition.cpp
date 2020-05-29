class Solution {
public:
    bool possibleBipartition(int N, vector<vector<int>>& dislikes) {
        
        //making adj list
        vector<vector<int>> graph(N);
        for(auto i: dislikes) {
            graph[i[0]-1].push_back(i[1]-1); // since N starts from 1, we -1 from every no to make N start from 0
            graph[i[1]-1].push_back(i[0]-1);
        }
        
        //ini color vector
        int n=graph.size();
        int color[n];
        memset(color, -1, sizeof(color));
        
        
        //dfs on every node if color is unset
        bool ans = true;
        for(int i = 0; i < n; i++) {
            if(color[i] == -1){
                ans = ans & dfs(i, -1, graph, color);
            }
            if(ans == false) 
                break;
        }

        return ans;
    }
    
    
    bool dfs(int i, int p, vector<vector<int>> &graph, int color[]){
        if(p == -1)
            color[i]=1;
        
        else {
            
            if(color[i] == color[p]) {
                return false;
            }

            if(color[p]==1) 
                color[i]=2;
            else color[i]=1;
        }
        
        bool ans = true;
        
        for(auto t: graph[i]){ //1, 0, 2, 3
            if(color[t] == -1){
                ans = ans & dfs(t, i, graph, color);//1
                if(color[t]==color[i]) {
                    ans = false;
                }    
            }
                
            else
                if(color[t]==color[i]) {
                    ans = false;
                }
                
            
            if(ans==false) 
                break;
        }
        
        return ans;
            
    }
};