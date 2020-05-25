class LRUCache {
public:
    int cap;
    unordered_map<int, list<pair<int, int>>::iterator> mp;
    list<pair<int, int>> l;
    int size;
    
    LRUCache(int capacity) {
        cap = capacity;
        size = 0;
    }
    
    
    
    void put(int key, int value) {
        if(!mp.count(key)) {
            if (size < cap){
                l.push_front({key, value});
                mp[key] = l.begin();
                size++;
            }
            else { // list full
                auto last = l.back();
                cout<<last.first<<endl;
                mp.erase(last.first);
                l.pop_back();
                l.push_front({key, value});
                mp[key] = l.begin();
            }
        }
        
        else{ // element aleready on map
            l.erase(mp[key]);
            l.push_front({key, value});
                mp[key] = l.begin();
        }
        
    }
    
    int get(int key) {
        if(mp.count(key)) {
            int val = (*mp[key]).second;
            l.erase(mp[key]);
            l.push_front({key, val});
            mp[key] = l.begin();
            return val;
        }
        
        return -1;
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */