class FindSumPairs {

    private int[] nums1;
    private int[] nums2;
    private HashMap<Integer, Integer> frequency = new HashMap<Integer, Integer>();

    // TC : O(n+m)
    public FindSumPairs(int[] nums1, int[] nums2) {
        this.nums1 = nums1; // O(n)
        this.nums2 = nums2; // O(m)

        // Update the frequency of nums2 as it is larger than nums1
        for(int nums: nums2) { // O(m)
            frequency.put(nums, frequency.getOrDefault(nums,0)+1);
        }
    }
    
    // TC : O(1)
    public void add(int index, int val) {
        // Decrease the frequency
        frequency.put(nums2[index], frequency.get(nums2[index])-1);

        // update the value from nums2
        nums2[index] += val;

        // Increse the frequency
        frequency.put(nums2[index], frequency.getOrDefault(nums2[index], 0)+1);
    }
    
    // TC : O(n)
    public int count(int tot) {
        int count = 0;

        for(int num: nums1) {
            count += frequency.getOrDefault(tot - num, 0);
        }

        return count;
    }
}

/**
 * Your FindSumPairs object will be instantiated and called as such:
 * FindSumPairs obj = new FindSumPairs(nums1, nums2);
 * obj.add(index,val);
 * int param_2 = obj.count(tot);
 */