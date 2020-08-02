class Solution {
public:
    vector<string> findItinerary(vector<vector<string>>& tickets) {
        int n = tickets.size();
        unordered_map<string, multiset<string>> mp;
        
        for(auto i: tickets) {
            mp[i[0]].insert(i[1]);
        }
        
        vector<string> ans;
        stack<string> st;

        st.push("JFK");

        while(!st.empty()) {
            
            string s = st.top();
            
            //if top element not on stack or the element's set has become empty.
            if(mp.find(s) == mp.end() or mp[s].size() == 0) { 
                st.pop();
                ans.push_back(s);
            }
            
            else{
                auto itr = mp[s].begin();
                st.push(*itr);
                mp[s].erase(itr);
            }
        }
        
        reverse(ans.begin(), ans.end());
        return ans;
    }
};