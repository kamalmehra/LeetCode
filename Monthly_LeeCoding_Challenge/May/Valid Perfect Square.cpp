
class Solution {
public:
    
    //root(n) sloution
//     bool isPerfectSquare(int num){
//         if(num == 0) return false;
        
//         for(long long i =1; i*i <= num ; i++){
//             if(i*i == num)
//                 return true;
//         }
//         return false;
//     }
    
    // log(n) solution recursive
//     bool isPerfectSquare(int num) {
//         if(num == 0) return false;
        
//         int low = 1;
//         int high = num;
//         return (bin_search (low, high, num));
//     }
    
//     bool bin_search(int low, int high, int num){
//         if(low > high) return false;
        
//         long long mid = low + (high - low)/2;
//         if(mid*mid == num){
//             cout<<mid<<endl;
//             return true;
//         }
        
//         bool ans1 =false, ans2 = false;
        
    
//         if(mid*mid < num){
//             ans1 = bin_search(mid+1, high, num);
//         }
        
//         else
//             ans2 = bin_search(low, mid-1, num);
        
//         return (ans1 or ans2);
        
//     }
    
    //logn solution iterative
    bool isPerfectSquare(int num){
        
        if (num == 0) return false;
        long long low = 1;
        long long high = num;
        long long mid;
        bool ans = false;
        
        while(low<=high){
            mid = low + (high - low)/2;
            long long sq = mid*mid;
            
            if ( sq == num){
                ans = true;
                break;
            }
            
            if(sq < num){
                low = mid + 1;
            }
            
            else{
                high = mid -1;
            }
        }
        return ans;
    }
};