class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        multiset<int> s;
        for(auto i: stones)
            s.insert(i);
                
        while(s.size()>1){
            int first = *(--s.end());
            cout<<"First "<<first;
            s.erase(--s.end());
            int second = *(--s.end());
            cout<<"   Second "<<second;
            s.erase(--s.end());
            int newStone = first - second;
            cout<<"    Newstone "<<newStone;
            if(newStone!=0)
                s.insert(newStone);
            
            cout<<endl;
        }
        
        if(s.size()==0)
            return 0;
        return *s.begin();
    }
};