class Solution {
public:


    // Function for the comparing the two strings
    static bool myCmp(std::string const &s1, std::string const &s2)
    {
        return (s1 < s2);
    }


    // Brute Force solution -> Convert the number to string apply the sorting then again convert the string to int.
    std::vector<int>solution1(int n)
    {
        std::vector<int> result;
        std::vector<std::string> tempVector;

        // 1. Convert the number from the int to string
        for(int i = 1; i <= n ; ++i)
        {
            tempVector.push_back(std::to_string(i));
        }

        // 2. Now apply the custom sort.
        sort(tempVector.begin(), tempVector.end(), myCmp);

        // 3. Again convert the string to int
        for(int i = 0; i < n; ++i)
        {
            result.push_back(std::stoi(tempVector[i]));
        }
        return result;
    }

    /*
        Analysis:
        Time Complexity : O(NlogN)
        Space Complexity : O(N) ---> Where N is the number of the strings 
    */    

    vector<int> lexicalOrder(int n) {
        return solution1(n);
    }
};