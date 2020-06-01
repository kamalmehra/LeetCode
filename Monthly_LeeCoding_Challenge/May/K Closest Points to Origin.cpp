class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int K) {
        int n = points.size();
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>> > pq; //distance, index
        for(int i = 0; i < n; i++) {
            pq.push({(points[i][0]*points[i][0] + points[i][1]*points[i][1]),i});
        }
        
        vector<vector<int>> ans;
        for(int i = 0; i < K; i++) {
            auto t = pq.top();
            pq.pop();
            ans.push_back(points[t.second]);
        }
        
        return ans;
    }
//better approach will be to fill only k elements on pq and then keep on popping till the end, at the end we will have k smallest elements
};