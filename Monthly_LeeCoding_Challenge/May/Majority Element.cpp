	class Solution {
public:
    int majorityElement(vector<int>& nums) {
        map<int, int> mp;
        
        for(auto i: nums){
            mp[i]++;
        }
        
        int m_count=-1;
        int ans;
        for(auto i: mp){
            if(m_count<i.second){
                m_count=i.second;
                ans=i.first;
            }
        }
        
        return ans;
    }
};