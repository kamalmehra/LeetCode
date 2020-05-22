class Solution {
public:
    int findJudge(int N, vector<vector<int>>& trust) {
        int n = trust.size();
        
        vector<int> adj[1001];
        
        //making adj matrix
        for(auto i: trust){
            adj[i[0]].push_back(i[1]);
        }
        
        int mayor = -1;
        for(int i = 1; i <= N; i++){
            if(adj[i].size() == 0)
                mayor = i;
        }
        
        //checking mayor in each person
        bool trust_mayor = false;
        for(int i = 1; i <= N; i++){
        
            if( i == mayor) continue;
        
            for(int j = 0; j < adj[i].size(); j++){
                if(adj[i][j] == mayor)
                    trust_mayor = true;
            }
            
            if(trust_mayor == false) return -1;
        }
        
        return mayor;
    }
};