class Solution {
public:


    // Brute Force solution : check for the each word in the string if it finds in the array of the string
    std::vector<std::string> solution1(const std::vector<std::string>&words){
        std::vector<std::string> response;

        set<std::string>st;

        for(int i = 0; i < words.size(); ++i){
            for(int j = i+1; j < words.size(); ++j){

                std::string s1 = words[i];
                std::string s2 = words[j];

                if(s1.length() > s2.length()){
                    std::size_t result = s1.find(s2);
                    // found
                    if(result != std::string::npos){
                        st.insert(s2);
                    }
                } else {
                    std::size_t result = s2.find(s1);
                    // found
                    if(result != std::string::npos){
                        st.insert(s1);
                    }
                }
            }
        }

        for(const std::string &s : st){
            response.push_back(s);
        }
        
        return response;
    }

    /*
        Analysis:
        Time Complexity : O(n^2*l)
        Space Complexity : O(1)
    */

    vector<string> stringMatching(vector<string>& words) {
        return solution1(words);
    }
};