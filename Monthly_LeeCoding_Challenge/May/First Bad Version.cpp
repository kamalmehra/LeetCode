// The API isBadVersion is defined for you.
// bool isBadVersion(int version);

class Solution {
public:
    int firstBadVersion(int n) {
        int l=1; 
        int h=n;
        int m;
        while(l<=h){
            m=l+(h-l)/2;
            if(isBadVersion(m)== false) l=m+1;
            else h=m-1;
        }
        return l;
        
    }
};