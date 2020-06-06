class Solution {
public:
    int total;
    vector<int> mp;
    
    Solution(vector<int>& w) {
        total = 0;
        srand(time(0));
        for(int i = 0; i < w.size(); i++) {
            total += w[i];
            mp.push_back(total);
        }
    }
    
    int pickIndex() {
        double x = double(rand())/double(RAND_MAX);
        double r = x*total;
        //binary search function
        int index = upper_bound(mp.begin(), mp.end(), r) - mp.begin();
        return index;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(w);
 * int param_1 = obj->pickIndex();
 */