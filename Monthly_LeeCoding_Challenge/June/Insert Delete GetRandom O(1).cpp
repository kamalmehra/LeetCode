class RandomizedSet {
public:
    /** Initialize your data structure here. */
    unordered_map<int,int> mp;
    vector<int> nums;
    
    RandomizedSet() {
    }
    
    /** Inserts a value to the set. Returns true if the set did not already contain the specified element. */
    bool insert(int val) {
        if(mp.find(val) != mp.end()) return false;
        
        nums.push_back(val);
        mp[val] = nums.size()-1;
        return true;

    }
    
    /** Removes a value from the set. Returns true if the set contained the specified element. */
    
    //To remove element, swap it with last entry on vector and corresponding values on map. THen remove the last element from vector and mp[val] from map
    bool remove(int val) {
        if(mp.find(val) == mp.end()) return false;
        
        int last = nums.back();
        mp[last] = mp[val];
        nums[mp[val]] = last;
        nums.pop_back();
        mp.erase(val);
        
        return true;
    }
    
    /** Get a random element from the set. */
    int getRandom() {
        double r = rand();
        double a = r/double(RAND_MAX);
        double rando = a*(nums.size()-1);
        int result = round(rando);
        return nums[result];
        
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */