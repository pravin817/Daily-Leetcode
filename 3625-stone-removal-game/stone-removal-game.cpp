class Solution {
public:
    bool canAliceWin(int n) {
        int count = 0;
        int step = 10;

        while(n >= step){
            n = n - step;
            --step;
            ++count;
        }

        return count%2 != 0;
    }
};

/*
    Analysis:
    Time Complexity : O(n)
    Space Complexity : O(1)
*/