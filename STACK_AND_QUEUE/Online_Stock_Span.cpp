/*
class StockSpanner {
public:
vector<int> arr;
stack<int> st;
    StockSpanner() {
        
    }
    
    int next(int price) {
        arr.push_back(price);
        int idx=arr.size()-1;
        while(!st.empty()&&arr[st.top()]<=price){
            st.pop();
        }
        int ans;
        if(st.empty()){
            ans=idx+1;
        }
        else{
            ans=idx-st.top();
        }
        st.push(idx);
        return ans;
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 *
*/