class FindSumPairs {
private:
    std::vector<int> nums1;
    std::vector<int> nums2;
    std::map<int, int> frequency;

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
    
    int count(int total) {

        int countOfPairs = 0;

        for(int i = 0; i < nums1.size(); ++i) {
            int complement = total - nums1[i];

            if (frequency.find(complement) != frequency.end()) {
                countOfPairs += frequency[complement];
            }
        }

        return countOfPairs;
    }
};

/**
 * Your FindSumPairs object will be instantiated and called as such:
 * FindSumPairs* obj = new FindSumPairs(nums1, nums2);
 * obj->add(index,val);
 * int param_2 = obj->count(tot);
 */