class Solution {
public:
    int subarraySum(vector<int>& a, int k) {
        int n = a.size();
        map<int, int> mp;
        int ans = 0;
        
        for(int i = 0; i<n; i++){
            if(i>0)
                a[i] += a[i-1];
            
            if(a[i] == k)
                ans++;
            
            if(mp.count(a[i]-k)){
                cout<<"mila\n";
                ans += mp[a[i]-k];
            }
            
            mp[a[i]] += 1;
        }
        
        return ans;
    }
};