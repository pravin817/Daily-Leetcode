class Solution {
public:

    vector<string> solution1( vector<string>&names, vector<int>&heights){
        int n = names.size();
        vector<string>ans;

        unordered_map<int, string>mp;

        // store the heights and names in the vector
        for(int i=0;i<n;++i){
            mp[heights[i]] = names[i];
        }

        // Sort the heights in decreasing order
        sort(heights.begin(), heights.end(), greater<int>());

        // Now find the value from the map and return
        for(int i = 0;i<n;i++){
            ans.push_back(mp[heights[i]]);
        }

        return ans;
    }

    /*  
        Analysis:
        Time Complexity : O(NlogN)
        Space Complexity : O(N)
    */    

    vector<string> sortPeople(vector<string>& names, vector<int>& heights) {
        return solution1(names, heights);
    }
};