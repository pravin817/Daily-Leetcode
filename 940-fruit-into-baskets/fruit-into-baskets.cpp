class Solution {
public:

    // Function used to calculate the total fruits
    int calculateTotalFruits(const std::vector<int>& fruits) {
        int n = fruits.size();

        int i = 0;
        int j = 0;
        int maximumFruitCount = 0;
        std::unordered_map<int,int>mp;

        while(j < n) {
            mp[fruits[j]]++;

            if(mp.size() <= 2) {
                maximumFruitCount = std::max(maximumFruitCount, j-i+1);
            } else {
                mp[fruits[i]]--;

                if(mp[fruits[i]] == 0){
                    mp.erase(fruits[i]);
                }
                ++i;
            }
            ++j;
        }

        return maximumFruitCount;
    }
    /*
        Analysis:
        Time Complexity  : O(n)
        Space Complexity : O(n)
    */

    int totalFruit(vector<int>& fruits) {
        return calculateTotalFruits(fruits);
    }
};