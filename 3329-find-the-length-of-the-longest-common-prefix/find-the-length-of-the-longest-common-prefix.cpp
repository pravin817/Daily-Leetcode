class Solution {
public:

    int length(int n)
    {
        std::string str = to_string(n);
        return str.size();
    }

    int longestCommonPrefix(vector<int>& arr1, vector<int>& arr2) {
        unordered_set<int>uset;

        for(auto it:arr1)
        {
            while(it > 0)
            {
                // Insert it into the set
                uset.insert(it);
                it = it / 10;
            }
        }

        int maxi = 0;

        for(int it:arr2)
        {
            while(it > 0)
            {
                if(uset.find(it)!=uset.end())
                {
                    // find

                    maxi = max(maxi,length(it));
                    break;
                }
                it/=10;
            }
        }
        return maxi;
    }
};