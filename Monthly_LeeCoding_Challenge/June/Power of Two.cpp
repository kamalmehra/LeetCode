class Solution {
public:
    bool isPowerOfTwo(int n) {
        
    // //METHOD  1 take log
    //     if(n <= 0) return false;
    //     int x = ceil(log2(n));
    //     int y = floor(log2(n));
    //     if(x == y) return true;
    //     return false;
    //
    
    //Method 2 using bit manipulation
        return (n <= 0 or n & n-1) ? false : true;
    
    }
};