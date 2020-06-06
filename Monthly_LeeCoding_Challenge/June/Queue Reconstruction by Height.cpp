class Solution {
public:
    //nlogn + n2
    vector<vector<int>> reconstructQueue(vector<vector<int>>& people) {
        int n = people.size();
        
        sort(people.begin(), people.end()); //sorting based on first value
        
        vector<vector<int>> ans(n,vector<int>(2, -1));
        for(auto i: people) { //for all people
            
            int count = i[1];
            for(auto &j: ans) { //iterating the array
                
                if(count == 0 and j[0] == -1) { //count indicates the no of digits gr than current digit 
                    j[0] = i[0];
                    j[1] = i[1];
                    break;
                }
                
                if(j[0] == -1 or j[0] >= i[0]) {
                    count -= 1;
                }
                
            }
        }
        return ans;
    }
};