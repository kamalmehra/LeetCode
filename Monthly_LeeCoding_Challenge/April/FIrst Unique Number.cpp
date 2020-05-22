class FirstUnique {
public:
    list<int> elements;
    unordered_map<int , list<int>::iterator> mp;
    unordered_map<int , int > banned ;
    FirstUnique(vector<int>& nums) {
        for(auto i : nums){
            if(!mp.count(i)){
                if(!banned[i]){
                    elements.push_front(i);
                    mp[i] = elements.begin();
                }
            }   
            else{
                if(!banned[i]){
                    elements.erase(mp[i]);
                    mp.erase(i);
                    banned[i] = 1;
                }
            }
        }
    }
    
    int showFirstUnique() {
        if(!elements.empty()){
            return elements.back();
        }
        else
            return -1;
    }
    
    void add(int value) {
        if(!mp.count(value)){
            if(!banned[value]){
                elements.push_front(value);
                mp[value] = elements.begin();
            }
        }
        else{ //6 //6 //6 
            if(!banned[value]){
                elements.erase(mp[value]);
                mp.erase(value);
                banned[value] =1;
             }
        }
    }
};

/**
 * Your FirstUnique object will be instantiated and called as such:
 * FirstUnique* obj = new FirstUnique(nums);
 * int param_1 = obj->showFirstUnique();
 * obj->add(value);
 */