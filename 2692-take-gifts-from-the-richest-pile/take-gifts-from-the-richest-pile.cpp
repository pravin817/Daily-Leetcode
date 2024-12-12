class Solution {
public:

    long long solution1(const std::vector<int> &nums, int k){
        priority_queue<int>pq;

        // Insert the all the elements in the priority queue
        int n = nums.size();

        for(int iPile = 0; iPile < n; ++iPile){
            pq.push(nums[iPile]);
        }

        long long count = 0;
        while(count < k){
            int top = pq.top();
            pq.pop();
            top = floor(sqrt(top));
            pq.push(top);
            ++count;
        }

        long long result = 0;
        while(!pq.empty()){
            int top = pq.top();
            pq.pop();
            result += top;
        }
        return result;
    }


    long long pickGifts(vector<int>& gifts, int k) {
        return solution1(gifts, k);
    }
};