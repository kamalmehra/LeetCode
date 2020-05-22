class Solution {
public:
    string removeKdigits(string num, int k) {
        string st;
        int s = -1; //pos til which st is filled
        
        for(auto i: num){
            while(s!=-1 and st[s] > i and k!=0){
                st.pop_back();
                s--;
                k--;
            }
            st.push_back(i);
            s++;
        }
        
        while(s>-2 and k!=0){
            st.pop_back();
            s--;
            k--;
        }
        
        //removing leading zeroes
        
        while(s>-2 and st[0]=='0'){
            cout<<"in ";
            st.erase(st.begin());
            s--;
        }
    
        
        if(st.length()==0)
            st.push_back('0');
        
        return st;
    }
};