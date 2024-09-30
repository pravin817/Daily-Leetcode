class CustomStack {

private:
    std::vector<int>st;
    std::vector<int>increments;
    int maxSize;    

public:
    CustomStack(int maxSize) {
        this->maxSize = maxSize;
    }
    
    void push(int x) {
        if(st.size() < maxSize)
        {
            st.push_back(x);
            increments.push_back(0);
        }
    }
    // O(1)
    
    int pop() {
        if(st.size() == 0)
            return -1;

        int idx = st.size()-1;

        // Lazy propogation
        if(idx > 0)
            increments[idx-1] += increments[idx];

        int value = st[idx] + increments[idx];

        // Remove from the stack and increments
        st.pop_back();
        increments.pop_back();

        return value;
    }
    // O(1)
    
    void increment(int k, int val) {
        
        int limit = min(k, (int)st.size()) - 1;

        if(limit >= 0)
            increments[limit] += val;
    }
    // O(1)
};

/**
 * Your CustomStack object will be instantiated and called as such:
 * CustomStack* obj = new CustomStack(maxSize);
 * obj->push(x);
 * int param_2 = obj->pop();
 * obj->increment(k,val);
 */