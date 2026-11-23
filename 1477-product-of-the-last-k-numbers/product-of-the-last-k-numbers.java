class ProductOfNumbers {

    List<Integer> result;

    public ProductOfNumbers() {
        result = new ArrayList<Integer>();
    }
    
    public void add(int num) {
        result.add(num);  // O(1)
    }
    
    public int getProduct(int k) {
        int answer = 1;
        int size = result.size() - 1;

        while (k > 0) {     // O(k)
            answer *= result.get(size);
            k--;
            size--;
        }

        return answer;
    }

    /*
        Analysis:
            Time Complexity  : O(k)
            Space Complexity : O(n)
    */
}

/**
 * Your ProductOfNumbers object will be instantiated and called as such:
 * ProductOfNumbers obj = new ProductOfNumbers();
 * obj.add(num);
 * int param_2 = obj.getProduct(k);
 */