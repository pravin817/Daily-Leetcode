class Solution {
public:
    vector<int> sequentialDigits(int low, int high) {
        string s = "123456789";
        vector<int>ans;

        for(int i = 2;i<=s.size();i++){
            for(int startIndex = 0;startIndex<=s.size()-i;startIndex++){
                string temp = s.substr(startIndex,i);
                int poss = stoi(temp);

                if(poss>=low && poss<=high){
                    ans.push_back(poss);
                }
            }
        }

        return ans;
    }


};