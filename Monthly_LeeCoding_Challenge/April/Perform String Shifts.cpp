class Solution {
public:
    string stringShift(string s, vector<vector<int>>& shift) {
        int total =0;
        
        for(int i =0 ;i <shift.size();i++){
            total+=shift[i][0] == 0 ? -shift[i][1] : shift[i][1]; 
        }
        cout<<total<<" ";
        if(total <0){
             total = abs(total) %((int)s.length());
            rotate(s.begin() , s.begin()+abs(total) , s.end());
            
        }
        else{
            
            total = (total) %((int)s.length());
            rotate(s.begin() , s.begin()+s.length()-total , s.end());
        }
        return s;
    }
};class Solution {
public:
    string stringShift(string s, vector<vector<int>>& shift) {
        int total =0;
        
        for(int i =0 ;i <shift.size();i++){
            total+=shift[i][0] == 0 ? -shift[i][1] : shift[i][1]; 
        }
        cout<<total<<" ";
        if(total <0){
             total = abs(total) %((int)s.length());
            rotate(s.begin() , s.begin()+abs(total) , s.end());
            
        }
        else{
            
            total = (total) %((int)s.length());
            rotate(s.begin() , s.begin()+s.length()-total , s.end());
        }
        return s;
    }
};