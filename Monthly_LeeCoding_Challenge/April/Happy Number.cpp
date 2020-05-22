//since input is in int, so max it will have 10 digits
//so max no after one itr = 10*81 = 810
//can minimize it to 18 itr max;

class Solution {
public:
    bool isHappy(int n) {
        unordered_map<int, int> mp; // to check whether sum appears again not
        while(n!=1){
            int sum = 0;
            if(mp.count(n))
                return false;
            mp[n]=1;
            
            for(int i = 10; n>0; i){
                sum+=(n%i)*(n%i);
                n = n/i;
            }
            n = sum;
        }
        
        return true;
    }
};