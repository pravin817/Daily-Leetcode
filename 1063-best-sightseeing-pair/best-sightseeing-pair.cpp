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

        // Vec[i] --> store the maximum values of values[i] + i till index i in values wala array
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


    // Optimal Solution we don't need the vector 
    int solution3(const std::vector<int> &nums){
        int n = nums.size();

        int maxScore = 0;

        int currentMax = nums[0] + 0;

        for(int i = 1; i < n; ++i){
            currentMax = max(currentMax, nums[i-1] + i-1);
            maxScore = max(maxScore , currentMax + nums[i] - i);
        }

        return maxScore;
    }

    /*
        Analysis:
        Time Complexity : O(N)
        Space Complexity : O(1)
    */    

    int maxScoreSightseeingPair(vector<int>& values) {
        return solution3(values);
    }
};