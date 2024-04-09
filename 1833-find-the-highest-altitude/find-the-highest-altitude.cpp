class Solution {
public:

    int solution1(vector<int>&gain){
        int len = gain.size();
        int maxi = 0;

        vector<int>ans;
        ans.push_back(0);
        // ans.push_back(gain[0]);

        // Calculate the prefix_sum
        for(int i = 1;i<len;i++){
            ans.push_back(ans[i-1]+gain[i]);
        }

        // Find the maximum number from the prefix_sum as the highest altitude
        for(int i = 0;i<ans.size();i++){
            // cout<<ans[i]<<" ";
            if(ans[i]>maxi){
                maxi = ans[i];
            }
        }
        return maxi;
    }

    /*
        Analysis:
        Time Complexity : O(N)
        Space Complexity : O(N)
    */    

    int solution2(vector<int>&gains){
        int len = gains.size();
        int sum = 0;
        int maxi = 0;

        for(int i = 0;i<len;i++){
            if((sum + gains[i])>maxi){
                maxi = sum + gains[i];
            }

            sum += gains[i];
        }

        return maxi;
    }

    /*
        Analysis:
        Time Complexity : O(N)
        Space Complexity : O(1)
    */
        
    int largestAltitude(vector<int>& gain) {
        return solution2(gain);
    }
};