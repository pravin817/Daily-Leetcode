class Solution {
public:

    // Solution - 1
    long long solution1(const std::vector<std::string> & instructions, const std::vector<int>& values) {
        int len = values.size();

        long long score = 0;
        int index = 0;
        std::vector<bool>visited(len, false);

        while(index >=0 && index < len) {

            // Check if the instruction is already processed
            if (visited[index]) {
                return score;
            }

            // mark the instruction as the visisted
            visited[index] = true;

            if (instructions[index] == "add") {
                score += values[index];
                ++index;
            } else {
                index += values[index];
            }
        }
        return score;
    }

    /*
        Analysis:
        Time Complexity : O(N)
        Space Complexity : O(N)
    */

    long long calculateScore(vector<string>& instructions, vector<int>& values) {
        return solution1(instructions, values);
    }
};