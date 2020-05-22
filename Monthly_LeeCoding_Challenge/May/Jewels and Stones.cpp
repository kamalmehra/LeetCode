class Solution {
public:
    int numJewelsInStones(string J, string S) {
        unordered_map<char, int> mp; //unordered map over ordered map for less time complexity
        
        for(auto i:J)
            mp[i]=0;
        
        int count=0;
        for(auto i : S)
            if(mp.count(i)) count++; //searcing key in map
        
        return count;
        
        
    }
};