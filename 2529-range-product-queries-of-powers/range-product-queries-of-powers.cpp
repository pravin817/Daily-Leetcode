class Solution {

private:
    std::vector<int> powers;

    long long M = 1e9+7;

    // Function used to build the powers array
    void buildPowersArray(int n) {
        for(int i = 0; i < 32; ++i) {
            if ((n & (1 << i)) != 0) {
                powers.push_back(1 << i);
            }
        }
    }

    /*
        Analysis:
        Time Complexity  : O(32) ==> O(1)
        Space Complexity : O(n)
    */

    // Print the powers Array
    void printPowersArray() {
        for(int i = 0; i < powers.size(); ++i) {
            cout << powers[i] << " ";
        }
        cout << endl;
    }


public:
    vector<int> productQueries(int n, vector<vector<int>>& queries) {
        buildPowersArray(n);

        vector<int> result;

        for(auto &query : queries) {
            int start = query[0];
            int end   = query[1];

            long long currentProduct = 1;
            for(int i = start; i <= end; ++i) { // 32
                currentProduct = (currentProduct * powers[i]) % M;
            }

            result.push_back(currentProduct);
        }

        return result;
    }

    /*
        Analysis:
        Time Complexity  : O(Q * 32) ===> O(Q), Where Q is the number of queries
        Space Complexity : O(32)
    */
};