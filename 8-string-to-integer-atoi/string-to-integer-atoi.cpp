class Solution {
public:
    int myAtoi(string s) {
        double result = 0;
        int len = s.size();
        bool signFlag = false;

        int i = 0;

        while(s[i] == ' '){
            i++;
        }

        bool isPositive = s[i] == '+';
        bool isNegative = s[i] == '-';

        isPositive == true ? i++ : i;
        isNegative == true ? i++ : i;

        while(i < len && s[i] >= '0' && s[i] <= '9'){
            int value = (int) (s[i] - '0');
            result = result*10 + value;
            i++;
        }

        result = isNegative ? -result : result;

        // Check the bound
        result = (result > INT_MAX) ? INT_MAX : result;
        result = (result < INT_MIN) ? INT_MIN : result;

        return (int)result;
    }
};

/*
    Analysis:
    Time Complexity : O(N)
    Space Compexity : O(1)
*/    