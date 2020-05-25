class Solution {
public:
    bool checkValidString(string s) {
        stack <int> openpar, star; //storing index of open par and star
        
        for(int i = 0; i < s.length(); i++){
            if(s[i] == ')'){
                if(!openpar.empty())
                    openpar.pop();
                else if(!star.empty())
                    star.pop();
                else
                    return false;
            }
            
            else if (s[i] == '(')
                openpar.push(i);
            
            else
                star.push(i);
                
        }
        
        while(!openpar.empty()) {
            if(!star.empty() and (star.top() > openpar.top()) ) {
                star.pop();
                openpar.pop();
            }
            
            else
                return false;
        }
        
        return true;
    }
};