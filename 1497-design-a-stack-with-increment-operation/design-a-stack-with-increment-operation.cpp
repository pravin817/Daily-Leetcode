class CustomStack {

private:
    std::vector<int> stack;
    int maxSize;

public:
    CustomStack(int maxSize) {
        this->maxSize = maxSize;
    }
    
    void push(int x) {
        if(stack.size() < maxSize)
        {
            stack.push_back(x);
        }
    }

    // O(1)
    
    int pop() {
        if(stack.size() == 0)
            return -1;

        int element = stack.back();
        stack.pop_back();
        return element;    
    }

    // O(1)
    
    void increment(int k, int val) {
        int limit = min(k, (int)stack.size());

        for(int i = 0; i < limit; ++i)
        {
            stack[i] += val;
        }
    }

    // O(N)
};

/**
 * Your CustomStack object will be instantiated and called as such:
 * CustomStack* obj = new CustomStack(maxSize);
 * obj->push(x);
 * int param_2 = obj->pop();
 * obj->increment(k,val);
 */