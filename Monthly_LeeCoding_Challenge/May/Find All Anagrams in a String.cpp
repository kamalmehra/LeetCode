class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        
        //TLE using unordered_multiset and comparing them
//         unordered_multiset<char> s1;
//         unordered_multiset<char> s2;
//         vector<int> ans;
        
//         for(auto i: p)
//             s1.insert(i);
        
//         int n = p.length();
//         int m = s.length();
        
//         for(int i = 0; i<n-1; i++)
//             s2.insert(s[i]);
        
//         for(int i = n-1; i<m; i++){
//             s2.insert(s[i]);
//             //print
//             for(auto itr = s2.begin(); itr!=s2.end(); ++itr)
            
//             if(s1 == s2){
//                 ans.push_back(i-n+1);
//             }
//            //removing the first element ==s[i-n+1]; elements are not in the order that they are inserted;
//             auto itr = s2.begin();
//             for(itr; itr!=s2.end(); itr++){
//                 if(*itr == s[i-n+1]){
//                     s2.erase(itr);
//                     break;
//                 }
//             }
//         }
        
//         return ans;
        
        //better approach, complexity = O(n+m)
        
        int n = s.length();
        int m = p.length();
        
        int check[26];
        memset(check, 0, sizeof(check));
        for(auto i: p){
            //increasing count of string p chars in check
            check[i-'a']++;
        }
    
        vector<int> ans;
        
        for(int i = 0; i<n; i++){
            //decreasing count corresponding to its index in check; (item added to window)
            check[s[i]-'a']-=1;
            
            if(i>=m){
                //making size of window == n, removing first element from window
                check[s[i-m]-'a']+=1;
            }
            
            int flag = 0;
            if(i>=m-1){
                //checking if all elements in check are 0 which is the required case;
                for(auto j: check){
                    if(j!=0)
                        flag = 1;
                }
                
                if(flag == 0)
                    ans.push_back(i-m+1);
            }
        }
        
        return ans;
        
    }
};