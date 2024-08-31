class Solution {
public:

    string solution1(string s)
    {
        int length = 0;
        istringstream ss(s);
        string word, reverseString;

        vector<string>stringVector;

        while(ss >> word)
        {
            stringVector.push_back(word);
        }

        length = stringVector.size();
        reverse(stringVector.begin(),stringVector.end());

        for(int i = 0; i < length ; ++i)
        {
            reverseString += stringVector[i];

            if(i!=length-1)
            {
                reverseString +=" ";
            }
        }

        return reverseString;
    }

    string reverseWords(string s) {
        return solution1(s);
    }
};