class Solution {
public:
    bool backspaceCompare(string S, string T) {
        stack<char> st;
        for(auto i: S){
            if(i == '#'){
                if(!st.empty())
                    st.pop();
            }
            else
                st.push(i);
        }
        S.clear();
        while(!st.empty()){
            S+=st.top();
            st.pop();
        }
        
        for(auto i: T){
            if(i == '#'){
                if(!st.empty())
                    st.pop();
            }
            else
                st.push(i);
        }
        T.clear();
        while(!st.empty()){
            T+=st.top();
            st.pop();
        }
        
        if(S == T)
            return true;
        return false;
    }
    
};