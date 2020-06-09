class Solution {
public:
    bool isSubsequence(string s, string t) {
        int n = s.size();
        int j = 0;
        for(int i = 0; i < t.size(); i++) {
            if(t[i] == s[j])
                j++;
        }
        if(j == n) return true;
        return false;
    }
    
};