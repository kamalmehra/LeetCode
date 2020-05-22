class Solution {
public:


//     int findComplement(int n){
        
//         if(n==0) return 1;
//         int num=0;
//         for(int i=0;num<n;i++){ //finding the no which has all bits set and is just greater than n
//             num+=pow(2,i);
//             cout<<num<<" ";
//         }
        
//         n=n^num;
//         return n;
//     }
    
    int findComplement(int n){
        //if(n==0) return 1; //no need since only +ve no. are present
        int x= log2(n)+1; // find position of MSB (no of bits used)
        for(int i=0;i<x;i++){ //flipping bits
            n= n ^ (1<<i);
        }
        
        return n;
        
    }
    
        
};
    