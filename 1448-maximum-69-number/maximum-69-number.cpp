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

    int maximum69Number (int num) {
        return getMaximum69Number(num);
    }
};