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
            tempVector.push_back(std::to_string(i));

        // 2. Now apply the custom sort.
        sort(tempVector.begin(), tempVector.end(), myCmp);

        // 3. Again convert the string to int
        for(int i = 0; i < n; ++i)
            result.push_back(std::stoi(tempVector[i]));

        return result;
    }

    /*
        Analysis:
        Time Complexity : O(NlogN)
        Space Complexity : O(N) ---> Where N is the number of the strings 
    */    


    // Solution - 2 By using the dfs (Recursion)

    void solve(int currentNumber, int limit, vector<int>&result)
    {

        // Base case
        if(currentNumber > limit)
            return;

        // small calculation + Recursive call
        result.push_back(currentNumber);

        // Ther number can be created by using the digits from 0 to 9
        for(int append = 0; append <= 9; ++append)
        {
            int newNumber = currentNumber * 10 + append;

            if(newNumber > limit)
                return;

            // Call the recursive function
            solve(newNumber, limit, result);    
        }    
    }

    vector<int> solution2(int n)
    {
        vector<int>result;

        for(int startNumber = 1; startNumber <= 9; ++startNumber)
            solve(startNumber, n, result);

        return result;    
    }

    /*
        Analysis:
        Time Complexity : O(N)
        Space Complexity : O(log2(N))  ---> O(N) ----> Where N is the number of the digits in the given number
    */    

    vector<int> lexicalOrder(int n) {
        return solution2(n);
    }
};