class Solution {
public:
    bool checkValidString(string s) {
        int hi = 0 , lo =0;
        for(auto i : s){
            lo+= i=='(' ? 1 : -1;
            hi+=i!=')' ? 1 : -1;
            if(hi<0) break;
            lo = max(lo , 0);
        }
                
        return (lo == 0);
    }
};