class Solution {
public:
    int countNumberOfSetBits(int number)
    {
        int setBitsCount = 0;

        while(number)
        {
            int lastBit = number % 2;

            setBitsCount += (lastBit & 1);

            // update the number
            number = number / 2;
        }
        return setBitsCount;
    }
    int minBitFlips(int start, int goal) {
        
        int number = start ^ goal;
        return countNumberOfSetBits(number);
    }

    /*
        Analysis:
        Time Complexity : O(d)   ---> where d is the number of the set bits in number
        Space Complexity : O(1)
    */    
};