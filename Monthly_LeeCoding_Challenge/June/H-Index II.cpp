class Solution {
public:
    int hIndex(vector<int>& citations) {
        int n = citations.size();
        for(int i = n-1; i >= 0; i--) {
            if(citations[i] < n-i) return n-i-1;
        }
        
        return n;
    }
};