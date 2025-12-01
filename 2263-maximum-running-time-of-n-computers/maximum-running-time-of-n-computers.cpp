class Solution {
public:

    bool isPossible(vector<int>&batteries, long long time, int computers){
      long long toTime = time*computers;

      for(long long bTime:batteries){
        toTime -=min(time,bTime);
      }


      return (toTime<=0);
    }

    long long maxRunTime(int n, vector<int>& batteries) {
        long long low = 0,high =0;

        int sz = batteries.size();

        // find the maximum i.e high 

        for(int i = 0;i<sz;i++){
          high+=batteries[i];
        }

        long long ans = 0;

        while(low<=high){
          // find the mid

          long long mid = low+(high-low)/2;

          if(isPossible(batteries,mid,n)){
            ans = mid;
            low = mid + 1;
          }else{
            high = mid - 1;
          }
        }

        return ans;
    }
};

/*
  Analysis:
  Time Complexity : O(nlogk)
  space Complexity : O(1)
*/  