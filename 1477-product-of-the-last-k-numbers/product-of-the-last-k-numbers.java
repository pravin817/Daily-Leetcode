class ProductOfNumbers {

    private List<Integer> result;
    private int size;

    public ProductOfNumbers() {
        result = new ArrayList<Integer>();
        size = 0;
    }
    
    public void add(int num) {
        // If the number is 0 then reset the result and size
        if (num == 0) {
            result = new ArrayList<Integer>();
            size = 0;
        } else {

            // If the element is the first
            if (size == 0) {
                result.add(num);
            } else {
                // Add the commulative product
                result.add(result.get(size-1) * num);
            }

            size++;
        }
    }

    public int getProduct(int k) {
        if (k > size) {
            return 0;
        } else if (k == size) {
            return result.get(size-1);
        } else {
            return (result.get(size-1) / result.get(size - k - 1));
        }
        
    }

    /*
        Analysis:
            Time Complexity  : O(1)
            Space Complexity : O(n)
    */
}

/**
 * Your ProductOfNumbers object will be instantiated and called as such:
 * ProductOfNumbers obj = new ProductOfNumbers();
 * obj.add(num);
 * int param_2 = obj.getProduct(k);
 */