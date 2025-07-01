class Solution {
private:

    // Function used to find the maximum wealth of the customer
    int calculateMaximumWealth(const std::vector<std::vector<int>>& accounts) {
        int rows = accounts.size();
        int cols  = accounts[0].size();

        int maximumWealth = 0;
        int currentWealth = 0;

        for(int ithRow = 0; ithRow < rows; ++ithRow) {
            currentWealth = 0;
            for(int jthCol = 0; jthCol < cols; ++jthCol) {
                currentWealth += accounts[ithRow][jthCol];
            }

            maximumWealth = max(maximumWealth, currentWealth);
        }
        return maximumWealth;
    }

    /*
        Analysis:
        Time complexity  : O(n*m), Where n is the number of the rows and m is the number of the columns
        Space Complexity : O(1)
    */

    int solution2(const std::vector<std::vector<int>>& accounts) {
        int maxWealth = 0;

        for(const auto& customer : accounts) {
            int currentWealth = 0;

            for(int money : customer) {
                currentWealth += money;
            }

            maxWealth = std::max(maxWealth, currentWealth);
        }

        return maxWealth;
    }

    /*
        Analysis:
        Time complexity  : O(n*m), where n is the number of the rows and m is the n umber of the columns
        Space complexity : O(1)
    */

public:
    int maximumWealth(vector<vector<int>>& accounts) {
        return solution2(accounts);
    }
};