class Solution {
public:
    int countElements(vector<int>& arr) {
        unordered_map<int ,int > mp ; 
        int ans = 0;
        for(auto i : arr){
            mp[i]++;
        }
        for(auto i : arr){
            if(mp.find(i+1)!=mp.end()){
                ans++;
                mp[i+1]--;
            }
        }
        return ans;
    }
};