class Solution {
public:
    int visited[1000][1000];
    int n_iland=0;
    
    int numIslands(vector<vector<char>>& grid) {
        int n=grid.size();
        if(n==0) return 0;
        int m=grid[0].size();
        
        //ini visited
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                visited[i][j]=0;
            }
        }
        
        //DFS
        for(int i=0; i<n; i++){
            for(int j=0;j<m; j++){
                if(visited[i][j]==0 and grid[i][j]=='1'){
                    // cout<<"sc"<<endl;
                    n_iland+=1;
                    get_iland(grid, i, j, n_iland);
                }
            }
        } 
        
        return n_iland;
    }
    
    void get_iland(vector<vector<char>>& grid, int n, int m, int n_iland){
        
        if(n<0 or n>=grid.size() or m<0 or m>=grid[0].size() or grid[n][m]=='0' or visited[n][m]==1) return;
        
        visited[n][m]=1;
        
        get_iland(grid, n, m+1, n_iland);
        get_iland(grid, n, m-1, n_iland);
        get_iland(grid, n-1, m, n_iland);
        get_iland(grid, n+1, m, n_iland);
        
        // cout<<" in get"<<endl;
        return;
                
    }
};