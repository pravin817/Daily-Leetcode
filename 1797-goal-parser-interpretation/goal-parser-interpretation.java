class Solution {
    public String interpret(String command) {
        StringBuilder builder = new StringBuilder();

        for (int idx = 0; idx < command.length(); idx++) {
            char currentChar = command.charAt(idx);

            if (currentChar == 'G') {
                builder.append('G');
            } else if (command.startsWith("()", idx))  {
                builder.append('o');
                idx++;
            } else if (command.startsWith("(al)", idx)) {
                builder.append("al");
                idx += 3;
            }
        }

        return builder.toString();
    }

    /*
        Analysis:
            Time Complexity  : O(n)
            Space Complexity : O(n)
    */
}