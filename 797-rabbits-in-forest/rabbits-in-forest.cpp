class Solution {
public:

    // Solution
    int numOfRabbits(const std::vector<int>& rabbits) {
        int totalRabbits = 0;
        std::unordered_map<int,int>countMap;

        for(int rabbit: rabbits) {
            countMap[rabbit]++;
        }

        for(const auto &entry:countMap) {
            int reportedOthers = entry.first;
            int reportCount = entry.second;
            int groupSize = reportedOthers + 1;
            int groupNeeded = std::ceil((double)reportCount / groupSize);

            totalRabbits += groupSize * groupNeeded;
        }

        return totalRabbits;
    }
    
    /*
        Analysis:
        Time Complexity  : O(N)
        Space Complexity : O(N)
    */

    int numRabbits(vector<int>& answers) {
        return numOfRabbits(answers);
    }
};