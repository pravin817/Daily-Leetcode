class FindSumPairs {
private:
    std::vector<int> nums1;
    std::vector<int> nums2;
    std::unordered_map<int, int> frequency;

public:
    FindSumPairs(vector<int>& nums1, vector<int>& nums2) {
        this->nums1 = nums1;
        this->nums2 = nums2;

        for (const auto& num : nums2) {
            ++frequency[num];
        }
    }
    
    void add(int index, int val) {
        int length = nums2.size();

        if(index >= 0 && index <= length-1) {
            --frequency[nums2[index]];
            nums2[index] += val;
            ++frequency[nums2[index]];
        }
    }

    // TC : O(1)
    
    int count(int total) {

        int countOfPairs = 0;

        for(const auto &num : nums1) {
            int complement = total - num;

            if (frequency.count(complement)) {
                countOfPairs += frequency[complement];
            }
        }

        return countOfPairs;
    }

    // TC : O(n)
};


/*
    Analysis:
    Time Complexity  : O(n + m + q1 + q2.n)
    Space Complexity : O(n+m)
*/

/**
 * Your FindSumPairs object will be instantiated and called as such:
 * FindSumPairs* obj = new FindSumPairs(nums1, nums2);
 * obj->add(index,val);
 * int param_2 = obj->count(tot);
 */