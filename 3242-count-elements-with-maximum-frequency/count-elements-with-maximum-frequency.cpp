class Solution {
public:
    int maxFrequencyElements(vector<int>& nums) {
        int maxi = INT_MIN,cnt = 0;
        map<int,int>mp;

        for(auto num:nums){
            mp[num]++;
        };

        for(auto m:mp){
            if(m.second >= maxi){
                maxi = m.second;
            }
        }

        

        for(auto m:mp){
            if(m.second == maxi){
                cnt+=m.second;
            }

            // cout<<"The element is : "<<m.first<<" and freq : "<<m.second<<" The maximum freq : "<<maxi<<" "<<cnt<<endl;
        }
        
        return cnt;
    }
};