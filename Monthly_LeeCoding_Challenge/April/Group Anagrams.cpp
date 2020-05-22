class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string,int> stored; //string, its index in ans vector
        int n = strs.size();
        vector<vector<string>> ans; // to store ans
        int it_ans = 0;
        for(int i = 0; i < n; i++){
            string temp = strs[i];
            sort(temp.begin(), temp.end());
            if(!stored.count(temp)){
                ans.push_back(vector<string> ({strs[i]}));
                stored[temp] = it_ans;
                it_ans++;
                cout<<strs[i]<<endl;
            }
            else{
            
                ans[stored[temp]].push_back(strs[i]);
            }
            
        }
        return ans;
        
    }
};class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string,int> stored; //string, its index in ans vector
        int n = strs.size();
        vector<vector<string>> ans; // to store ans
        int it_ans = 0;
        for(int i = 0; i < n; i++){
            string temp = strs[i];
            sort(temp.begin(), temp.end());
            if(!stored.count(temp)){
                ans.push_back(vector<string> ({strs[i]}));
                stored[temp] = it_ans;
                it_ans++;
                cout<<strs[i]<<endl;
            }
            else{
            
                ans[stored[temp]].push_back(strs[i]);
            }
            
        }
        return ans;
        
    }
};