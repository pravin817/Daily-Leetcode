class Solution {
public:

    int maxCountByBruteForce(std::vector<int>& banned, int n, int maxSum){
        int count = 0;
        int len = banned.size();
        int currentSum = 0;
        std::sort(banned.begin(), banned.end());

        int i = 1; // 1 to n Range 
        int j = 0; // Over the array

        while(i <= n){
            if(banned[j] != i){
                currentSum += i;
                ++i;
                if(currentSum <= maxSum){
                    ++count;
                }else{
                    return count;
                }
            }else{
                if(j < len){
                    ++j;
                }
            }
        }
        return count;
    }


    int solution2(std::vector<int>& banned, int n, int maxSum){
        int count = 0;
        int currentSum = 0;
        int len = banned.size();

        unordered_set<int>s(banned.begin(),banned.end());

        for(int i = 1; i <= n; ++i){
            if(s.count(i)){
                // found
                continue;
            }else{
                // Check the sum
                if(currentSum + i <= maxSum){
                    currentSum += i;
                    ++count;
                }else{
                    break;
                }
            }
        }
        return count;
    }

    /*
        Analysis:
        Time Complexity : O(n*m)
        Space Complexity : O(n)
    */    
    int maxCount(vector<int>& banned, int n, int maxSum) {
        return solution2(banned, n, maxSum);
    }
};