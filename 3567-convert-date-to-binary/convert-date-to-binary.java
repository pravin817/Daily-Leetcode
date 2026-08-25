class Solution {

    // Function used to check if the string is empty
    private boolean isEmpty(String s) {
        return s == null || s.isEmpty();
    }


    // Function used to get the binary representation of the number
    private String binary(int num) {

        if (num == 1) {
            return "1";
        }

        StringBuilder builder = new StringBuilder();

        while(num != 0) {
            int remainder = num % 2;
            num /= 2;

            if (remainder == 1) {
                builder.append("1");
            } else {
                builder.append("0");
            }
        }

        return builder.reverse().toString();
    }

    private String solution1(String date) {
        String year  = binary(Integer.parseInt(date.substring(0,4)));
        String month = binary(Integer.parseInt(date.substring(5,7)));
        String day   = binary(Integer.parseInt(date.substring(8,10)));

        return year + "-" + month + "-" + day;
    }

    /*
        Analysis:
            Time Complexity  : O(logn)
            Space Complexity : O(n)
    */

    public String convertDateToBinary(String date) {
        return solution1(date);
    }
}