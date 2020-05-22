class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        vector<int> count(26, 0);
        
        for(auto i: s1){
            count[i-'a']++;
        }
        
        int m = s1.length();
        int n = s2.length();
        if(m==0) return true;
        
        for(int i = 0; i<n; i++){
            
            count[s2[i]-'a']--;
            
            if(i>=m){
                count[s2[i-m]-'a']++;
            }
            
            
            int flag = 0;
            
            if(i>=m-1){
                for(auto i: count){
                if(i!=0)
                    flag = 1;
                }

                if(flag == 0)
                    return true;
            }
        }
        
        return false;
    }
    
};