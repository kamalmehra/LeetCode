class Solution {
public:
    vector<vector<pair<int, int>>> adj; //node, weight
    vector<bool> visited;
    int min_fare;
    int dest;
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int K) {
        
        //dfs + pruning method
        if(flights.size() == 0) return -1;
        if(src == dst) return 0;
        
        //convert edgelist to adj list
        adj.resize(n);
        for(auto i: flights)
            adj[i[0]].push_back(make_pair(i[1], i[2]));
        
        visited.resize(n, false);
        min_fare= INT_MAX;
        dest = dst;
        
        dfs(src, 0, K);
        
        return min_fare == INT_MAX ? -1: min_fare;
        
    }
    
    void dfs(int curr, int fare, int k) {
        if(k < -1 or fare >= min_fare) return;
        
        if(curr == dest) {
            min_fare = min(min_fare, fare);
        }
        
        visited[curr] = true;
        
        for(auto i: adj[curr]) {
            if(visited[i.first] == false) dfs(i.first, fare + i.second, k-1);
        }
        
        visited[curr] = false;
    }
};