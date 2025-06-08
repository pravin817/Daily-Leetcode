class Solution {
public:

    // Brute force solution : Create the array then sort it
    std::vector<int> solution1(int n) {
        std::vector<int> result;

        for(int iNumber = 1 ; iNumber <= n; ++iNumber) {
            result.push_back(iNumber);
        }

        // Sort the array lexicographically
        std::sort(result.begin(), result.end(), [](int num1, int num2) {
            return std::to_string(num1) < std::to_string(num2);
        });

        return result;
    }

    /*
        Analysis:
        Time Complexity : O(nlogn)
        Space Complexity : O(n)
    */

    vector<int> lexicalOrder(int n) {
        return solution1(n);        
    }
};