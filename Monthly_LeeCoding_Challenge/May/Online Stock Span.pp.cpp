class StockSpanner {
public:
    
    //Can replace deque with stack
    deque <pair<int, int>> dq; //index, count(stack smaller before it)
    StockSpanner() {
        
    }
    
    
    int next(int price) {
        
        int ans = 1;
        
        //if dq is empty return 1
        if(dq.empty()){
            dq.push_front({price,1});
        }
        
        else{
            //if dq is not empty then check if back elements price is less  not not, if less then remove the element and add its count to ans repeat. In the end push the current price and count
            while(dq.back().first<= price and dq.empty()==0){
                ans+=dq.back().second;
                dq.pop_back();
                cout<<price<<endl;
            }
            dq.push_back({price,ans});
        }
        
        return ans;
        
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */