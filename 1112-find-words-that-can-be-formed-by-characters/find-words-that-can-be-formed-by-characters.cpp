class Solution {
public:
    int countCharacters(vector<string>& words, string chars) {

        vector<int> chFreq(26, 0);
  
        for(auto ch : chars) {
            chFreq[ch - 'a']++;
        }
        
        int ans = 0;
        for(auto str : words){
            bool flag = true;

            vector<int> copyFreq(26, 0);
            
            for(auto ch : str) {
                if(++copyFreq[ch - 'a'] > chFreq[ch - 'a']){
                    flag = false;
                    break;
                }
            }

            if(flag) ans += str.size();
        }
        return ans;
    }
};