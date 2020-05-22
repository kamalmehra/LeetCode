class Solution {
public:
    string frequencySort(string s) {
        map<char, int> mp;
        for(auto i: s){
            mp[i]++;
        }
        
        priority_queue<pair<int, char>> pq;
        for(auto i: mp)
            pq.push({i.second, i.first});
        
        string ans;
        while(!pq.empty()){
            auto t=pq.top();
            pq.pop();
            for(int i=0; i<t.first;i++)
                ans.push_back(t.second);
                
        }
        return ans;
    }
};