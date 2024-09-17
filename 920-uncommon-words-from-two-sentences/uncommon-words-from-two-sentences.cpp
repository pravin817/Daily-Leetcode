class Solution {
public:

    vector<string> solution1(string s1, string s2)
    {
        std::map<std::string , int>mp;
        std::vector<std::string>result;

        // Add the words from the string s1
        std::stringstream ss(s1);
        std::string word;

        while (ss >> word)
            mp[word]++;

        // Add the words from the string s2
        std::stringstream ss2(s2);
        while (ss2 >> word)
            mp[word]++;

        // traverse the map
        for(auto m:mp)
        {
            if(m.second == 1)
            result.push_back(m.first);
        }

        return result;
    }

    /*
        Analysis:
        Time Complexity: O(nlogn) 
        Space Complexity: O(k) --> where k is the unique words in the string
    */    

    vector<string> uncommonFromSentences(string s1, string s2) {
        return solution1(s1,s2);
    }
};