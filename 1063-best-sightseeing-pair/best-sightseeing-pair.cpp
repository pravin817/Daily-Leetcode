class Solution {
public:

    // Function that finds the maximum score
    int findMaximumScoreInSightseeingPair(const std::vector<int>&nums){
        int maxScore = INT_MIN;
        int n = nums.size();
        for(int i = 0; i < n; ++i){
            for(int j = i+1; j < n; ++j){
                maxScore = max(maxScore , (nums[i] + nums[j] + i - j));
            }
        }
        return maxScore;
    }
    /*
        Analysis:
        Time Complexity : O(N^2) , Where N is the number of the elements in the vector
        Space Complexity : O(1)
    */

    // Note the above solution gives the TLE

    // We can arrage the formula ===> (nums[i] + i) + (nums[j] - j)

    int solution2(const std::vector<int>&values){
        int maxScore = INT_MIN;
        int n = values.size();
        std::vector<int>vec(n,0);
        vec[0] = values[0];

        // Values[i] + i
        for(int i = 1; i < n; ++i){
            vec[i] = max(values[i] + i , vec[i-1]);
        }

        for(int j = 1; j < n; ++j){
            maxScore = max(maxScore, values[j] - j + vec[j-1]);
        }
        
        return maxScore;
    }
    /*
        Analysis:
        Time Complexity : O(N)
        Space Complexity : O(N)
    */    

    int maxScoreSightseeingPair(vector<int>& values) {
        return solution2(values);
    }
};