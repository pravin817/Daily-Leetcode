class Solution {
public:

    vector<int>solution1(vector<int>&deck){
        int n = deck.size();
        vector<int>result(n,0);

        // Sort the deck
        sort(deck.begin(),deck.end());

        // skip
        bool skip = false;

        int i = 0; // For the deck
        int j = 0; // For the result

        while(i<n){
            if(result[j] == 0){
                if(skip == false){
                    result[j] = deck[i];
                    i++;
                }

                // change the skips status
                skip = !skip;
            }

            // Move the j
            j = (j+1)%n;
        }

        return result;
    }
    /*
        Analysis:
        Time Complexity : O(nlogn)
        Space Complexity : O(n) ----> for the result if excluded then O(1)
    */    

    vector<int> deckRevealedIncreasing(vector<int>& deck) {
       return solution1(deck);
    }
};
