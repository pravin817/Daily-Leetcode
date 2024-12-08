class Solution {
public:
    // Solution by exploring the each event  --> Gives TLE
    int maxTwoEventsBrutForce(const std::vector<std::vector<int>>&events){
        int result = 0;

        int eventCount = events.size();

        for(int iEvent = 0; iEvent < eventCount; ++iEvent){
            int value = events[iEvent][2];

            result = max(result, value);

            for(int jEvent = 0; jEvent < eventCount; ++jEvent){
                if(iEvent == jEvent){
                    continue;
                }else if(events[iEvent][1] >= events[jEvent][0]){
                    continue;
                }else{
                    result = max(result, value + events[jEvent][2]);
                }
            }
        }
        return result;
    }

    /*
        Analysis:
        Time Complexity : O(N^2)
        Space Complexity : O(1)
    */    


    // Upper bound 
    int BinarySearch(std::vector<std::vector<int>>&events, int target){
        int low = 0;
        int high = eventCount - 1;
        int result = eventCount;

        while(low <= high){
            int mid = low + (high - low)/2;

            if(events[mid][0] > target ){
                result = mid;
                high = mid - 1;
            }else{
                low = mid + 1;
            }
        }
        return result;
    }

    int eventCount;
    int t[100001][3];
    int solve(std::vector<std::vector<int>>&events, int currentIdx, int count){

        if(count == 2 || currentIdx >= eventCount){
            return 0;
        }

        if(t[currentIdx][count] != -1){
            return t[currentIdx][count];
        }

        // 1. Skip the event
        int skipEvent = solve(events, currentIdx+1, count);

        // 2. Attend the event
        int nextValidIndex = BinarySearch(events,events[currentIdx][1]);
        int takeEvent = events[currentIdx][2] + solve(events,nextValidIndex,count+1);

        return t[currentIdx][count] = max(skipEvent, takeEvent);
    }

    int solution2(std::vector<std::vector<int>>&events){
        eventCount = events.size();

        // 1. Sort
        std::sort(events.begin(), events.end());
        int currentIdx = 0, count = 0;

        memset(t,-1,sizeof(t));
        return solve(events, currentIdx, count);
    }
    /*
        Analysis:
        Time Complexity : O(NlogN)
        Space Complexity : O(N)
    */    

    int maxTwoEvents(vector<vector<int>>& events) {
        return solution2(events);
    }
};