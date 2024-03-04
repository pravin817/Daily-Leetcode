class Solution {
public:
    int bagOfTokensScore(vector<int>& tokens, int power) {

        // Get the tokens size
        int n = tokens.size();

        int maxScore = 0; // Initially given

        // Sort the tokens
        sort(tokens.begin(),tokens.end());

        // score
        int score = 0;

        // two points 
        int i = 0, j = n-1;  // i ===> score++ , power -=token[i],   ||||| j ===> score--, power+=token[i];

        while(i<=j){

            if(power>=tokens[i]){
                power-=tokens[i];
                score = score +1;
                i++;

                maxScore = max(maxScore,score);
            }else if(score>=1){
                power+=tokens[j];
                score--;
                j--;
            }else{
                return maxScore;
            }
        }

        return maxScore;
    }
};


/*
    Analysis:
    Time Complexity : O(nlogn)
    Space Complexity : O(1)
*/    