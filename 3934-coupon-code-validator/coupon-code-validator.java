class Solution {

    // Function used to check if the coupon is valid or not
    private boolean isValideCouponCode(String code) {

        if (code == null || code.length() == 0 ){
            return false;
        }

        for (int i = 0; i < code.length(); ++i) {
            char ch = code.charAt(i);

            if ((ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z') || (ch >= '0' && ch <= '9')  || ch == '_') {
                continue;
            } else {
                return false;
            }
        }

        return true;
    }

    /* 
        Analysis:
            Time Complexity  : O(n)
            Space Complexity : O(1)
    */

    public List<String> validateCoupons(String[] code, String[] businessLine, boolean[] isActive) {
        
        Map<String, Integer> hashMap = new HashMap<String, Integer>();

        hashMap.put("electronics", 0);
        hashMap.put("grocery", 1);
        hashMap.put("pharmacy", 2);
        hashMap.put("restaurant", 3);

        List<Pair> resultList = new LinkedList<Pair>();

        for (int i = 0; i < code.length; ++i) {
            if (isActive[i] && isValideCouponCode(code[i]) && hashMap.containsKey(businessLine[i])) {
                resultList.add(new Pair(hashMap.get(businessLine[i]), code[i]));
            }
        }

        Collections.sort(resultList);

        List<String> result = new LinkedList<String>();

        for (Pair pair: resultList) {
            result.add(pair.code);
        }

        return result;
    }

    /*
        Analysis:
            Time Complexity  : O(n^2)
            Space Complexity : O(n)
    */

    private static class Pair implements Comparable<Pair> {
        int order;
        String code;

        Pair(int order, String code) {
            this.order = order;
            this.code = code;
        }

        @Override
        public int compareTo(Pair other) {
            if (this.order != other.order) {
                return Integer.compare(this.order, other.order);
            }

            return this.code.compareTo(other.code);
        }
    }
}