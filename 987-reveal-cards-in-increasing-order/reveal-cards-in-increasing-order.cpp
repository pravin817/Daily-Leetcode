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

    vector<int>solution2(vector<int>&deck){
        int n = deck.size();

        queue<int>q;

        vector<int>result(n,0);

        // Sort
        sort(deck.begin(),deck.end());

        for(int i = 0;i<n;i++){
            q.push(i);
        }


        for(int i = 0;i<n;i++){
            int idx = q.front();
            q.pop();

            result[idx] = deck[i];

            if(!q.empty()){
                q.push(q.front());
                q.pop();
            }
        }
        return result;
    }

    /*
        Analysis:
        Time Complexity : O(nlogn)
        Space Complexity : O(n) 
    */    

    vector<int> deckRevealedIncreasing(vector<int>& deck) {
       return solution2(deck);
    }
};
