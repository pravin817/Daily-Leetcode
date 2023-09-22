class Solution {
public:

    bool solution1(string s, string t){
        int m = s.length();
        int n = t.length();

        int i = 0, j = 0;

        while(i < m && j < n){
            if(s[i] == t[j]){
                i++;
            }
            j++;
        }

        if(i == m){
            return true;
        }else{
            return false;
        }
    }

    /*
        Analysis:
        Time Complexity : O(m+n)
        Space Complexity : O(1)
    */


    bool solution2(string s, string t){
        int m = s.length();
        int n = t.length();

        // create the vector to store the char with its idx 
        map<char,vector<int>>mp;

        for(int i = 0;i<n;i++){
            mp[t[i]].push_back(i);
        }

        int prev = -1;

        // now iterate through the s
        for(int i = 0;i<m;i++){

            char ch = s[i];

            if(mp.find(ch)==mp.end()){
                return false;
            }

            vector<int>indices = mp[ch];

            auto it = upper_bound(begin(indices),end(indices),prev);   // log(n)

            if(it == indices.end()){
                return false;
            }

            prev = *it;
        }
        return true;
    }

    /*
        Analysis:
        Time Complexity : O(mlogn)
        Space Complexity : O(1)
    */    

    bool isSubsequence(string s, string t) {
        return solution2(s,t);
    }
};