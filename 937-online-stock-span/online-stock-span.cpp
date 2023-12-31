class StockSpanner {
private:
    stack<pair<int,int>> st; //value and index
    int index;
public:
    StockSpanner() {
        index = -1;
    }
    
    int next(int price) {
        index++;
        //first remove of the ple and find pge
        while(!st.empty() && st.top().first <= price)
            st.pop();
        
        if(st.empty()) {
            st.push({price, index});
            return index + 1;
        }
        else {
            int span = index - st.top().second;
            st.push({price, index});
            return span;
        }
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */
 //problem is very simple same as stock span problem in gfg
 //here we need to implement with little bit of oops concept
 //also just return the value wheever the next is called 
 //no need to maintain a vector as we did in gfg