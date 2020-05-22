    class Solution {
    public:
        bool canConstruct(string ransomNote, string magazine) {
            int a[30]={0};
            for(auto i: ransomNote){
                a[i-'a']++;
            }
            for(auto i: magazine){
                if(a[i-'a']>0)
                    a[i-'a']--;
            }

            int ans=1;
            for(auto i: a){
                if(i!=0) ans=0;
            }

            return ans;

        }
    };