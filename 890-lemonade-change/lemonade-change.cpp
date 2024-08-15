class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        int length = bills.size();

        int cnt5 = 0;
        int cnt10 = 0;
        int cnt20 = 0;

        for(int i = 0; i < length; ++i)
        {
            if(bills[i] == 5)
            {
                ++cnt5;
            }
            else if(bills[i] == 10)
            {
                ++cnt10;

                if(cnt5 - 1 >= 0){
                    --cnt5;
                }else
                {
                    return false;
                }
            }else{
                ++cnt20;

                if(cnt5-1 >= 0 && cnt10-1>= 0){
                    cnt5--;
                    cnt10--;
                }else if(cnt5-3 >= 0){
                    cnt5 = cnt5 - 3;
                }else
                {
                    return false;
                }
            }
        }

        return true;
    }
};

/*
    Analysis:
    Time Complexity : O(N)
    Space Complexity : O(1)
*/    