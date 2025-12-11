class Solution {
public:

    int countCoverBuildingsOptimised(int n, std::vector<std::vector<int>>& buildings) {
        std::unordered_map<int, std::pair<int, int>> xToMinMaxY;
        std::unordered_map<int, std::pair<int, int>> yToMinMaxX;

        // Populate the min and max map for the x and y
        for (auto &building : buildings) {
            int x = building[0];
            int y = building[1];

            if (!xToMinMaxY.count(x)) {
                xToMinMaxY[x] = {INT_MAX, INT_MIN};
            }

            if (!yToMinMaxX.count(y)) {
                yToMinMaxX[y] = {INT_MAX, INT_MIN};
            }

            // Update the data
            xToMinMaxY[x].first = min(xToMinMaxY[x].first, y);
            xToMinMaxY[x].second = max(xToMinMaxY[x].second, y);

            yToMinMaxX[y].first = min(yToMinMaxX[y].first, x);
            yToMinMaxX[y].second = max(yToMinMaxX[y].second, x);
        }

        int count = 0;

        for (auto &building : buildings) {
            int x = building[0];
            int y = building[1];

            auto& xWithRespectToY = yToMinMaxX[y];
            auto& yWithRespectToX = xToMinMaxY[x];

            if (xWithRespectToY.first < x && x < xWithRespectToY.second && 
                yWithRespectToX.first < y && y < yWithRespectToX.second) {
                    ++count;
                }
        }

        return count;
    }

    /*
        Analysis:
            Time Complexity  : O(n)
            Space Complexity : O(n)
    */

    int countCoveredBuildings(int n, vector<vector<int>>& buildings) {
        return countCoverBuildingsOptimised(n, buildings);
    }
};