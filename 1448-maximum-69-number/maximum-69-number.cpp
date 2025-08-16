class Solution {
public:

    // Function used to get the maximum 69 number
    int getMaximum69Number(int num) {

        // 1. Convert the int -> string
        string intString = to_string(num);

        // 2. Traverse the string and find the first 6 if it has the 6 then replace it with 9
        for(int i = 0; i < intString.size(); ++i) {
            if(intString[i] == '6') {
                intString[i] = '9';
                break;
            }
        }

        // 3. Convert the string -> int
        return stoi(intString);
    }

    /*
        Analysis:
        Time Complexity  : O(n)
        Space Complexity : O(n),
                                    Where n is the number of the number of the digits in a given number
    */


    /*
        We can solve this problem in a simple and efficient way.
        To maximize the number, we need to change the first (leftmost) occurrence of digit 6 to 9.
        Instead of converting the number to a string, we can iterate through its digits and
        keep track of the position of the leftmost 6 (from the most significant digit).

        Once we find the position, we calculate the amount to add to the original number
        to convert that 6 into a 9. Since 9 - 6 = 3, we add:
            3 * pow(10, position)

        This gives us the maximum number possible by changing at most one digit.
    */

    int getMaximum69Number2(int num) {
        int leftMost6Position = -1;

        int temp = num;
        int position = 0;

        while(temp > 0) {
            int lastDigit = temp % 10;

            if (lastDigit == 6) {
                leftMost6Position = position;
            }

            // update temp and position
            temp = temp / 10;
            ++position;
        }
        return leftMost6Position == -1 ? num : num + 3 * pow(10, leftMost6Position);
    }

    /*
        Analysis:
        Time Complexity  : O(logn)
        Space Complexity : O(1)
    */

    int maximum69Number (int num) {
        return getMaximum69Number2(num);
    }
};