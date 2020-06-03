//to sort the vector<pair<int,int>> in desc order
bool sortinrev(const pair<int,int> &a, const pair<int,int> &b) { 
       return (a.first > b.first); 
} 

class Solution {
public:
    int twoCitySchedCost(vector<vector<int>>& costs) {
        int n = costs.size();
        vector<pair<int, int>> diff; //diff b/w a and price for a person
        for(int i = 0; i < n ; i++) {
            diff.push_back(make_pair(abs(costs[i][0] - costs[i][1]), i));
        }
        
        //sorting according to diff b/w prices, highest diff on top
        sort(diff.begin(), diff.end(), sortinrev);
        
        
        int countA = 0;
        int countB = 0;
        int total = 0;
        int i = 0;
        
        //taking the max diff position and adding its minimun value to total
        while(countA < n/2 and countB < n/2) {
            int currIndex = diff[i].second;
            if(costs[currIndex][0] < costs[currIndex][1]) { 
                countA += 1;
                total += costs[currIndex][0];
            }
            
            else if(costs[currIndex][0] > costs[currIndex][1]) {
                countB += 1;
                total += costs[currIndex][1];
            }
            
            else {
                if(countA <= countB) {
                    countA += 1;
                    total +=costs[currIndex][0];
                }
                else {
                    countB += 1;
                    total += costs[currIndex][1];
                }
            }
            
            i++;
        }
        
        if(countA < n/2) { // add remaining positions to A (if any)
            for(i; i < n; i++) {
                int currIndex = diff[i].second;
                total += costs[currIndex][0];
            }
        }
        
        else if(countB < n/2) { // add remaining positions to B (if any)
            for(i; i < n; i++) {
                int currIndex = diff[i].second;
                total += costs[currIndex][1];
            }
        }
        
        return total;
        
    }
};