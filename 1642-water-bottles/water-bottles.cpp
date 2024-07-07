class Solution {
public:

    // Brute Force solution By Simulation
    int solution1(int numBottles, int numExchange){
        int consumed = 0;

        while(numBottles >= numExchange){

            consumed += numExchange;

            // Remove the numExchange bottles from the numBottles
            numBottles -= numExchange;

            // Add one Full bottle
            numBottles +=1;
        }

        return consumed+numBottles;
    }

    /*
        Analysis:
        Time Compelxity : O(N)
        Space Complexity : O(1)
    */    

    int solution2(int numBottles, int numExchange){
        int consumed = numBottles;
        int emptyBottles = numBottles;

        while(emptyBottles >= numExchange){

            int extraFullBottles = emptyBottles / numExchange;
            int remain = emptyBottles % numExchange;

            emptyBottles = extraFullBottles + remain;

            consumed +=extraFullBottles;
        }
        return consumed;
    }

    /*
        Analysis:
        Time Complexity : O(logN)
        Space Complexity : O(1)
    */    

    int numWaterBottles(int numBottles, int numExchange) {
        int ans = 0;

        ans += numBottles;
        while(numBottles>=numExchange){
            ans += (numBottles / numExchange);
            numBottles = numBottles%numExchange + (numBottles / numExchange);
        }

        return ans;


        // return solution2(numBottles, numExchange);
    }
};