class Solution {
public:
    int passThePillow(int n, int time) {
        return n - abs(n - 1 - time % (n * 2 - 2));
    }
};

/*
    Analysis:
    Time Complexity : O(1)
    Space Complexity : O(1)
*/    