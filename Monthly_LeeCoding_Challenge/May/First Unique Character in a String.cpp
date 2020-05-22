	class Solution {
public:
    int firstUniqChar(string s) {
        int h[26];
        memset(h,-1,sizeof(h));
        //insert string in h, if h[i]!= -1 then update it with index
        //if h[i] is -1 then it has never come, if -2 then more than 1, if some no. then that no is the index. Find min index and retrun it
        for(int i=0;i<s.length();i++){
            if(h[s[i]-'a']==-1) h[s[i]-'a']=i;
            
            else if(h[s[i]-'a']!=-2) h[s[i]-'a']=-2;
        }
        
        int min=INT_MAX;
        for(int i=0;i<26;i++)
            if(h[i]!=-1 and h[i]!=-2 and h[i]<min) min=h[i];
        
        return (min==INT_MAX?-1:min);
        
        
    }
};