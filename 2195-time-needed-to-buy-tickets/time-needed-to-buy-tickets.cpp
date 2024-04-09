class Solution {
public:

    // Brute Force by using the queue
    int solution1(vector<int>&tickets, int k){
        int len = tickets.size();
        int time = 0;
        queue<int>q;

        // Insert all the tickets into the queue
        for(int i = 0;i<len;i++){
            // Push the index
            q.push(i);
        }

        while(!q.empty()){

            //Increase the time
            time++;

            int front = q.front();
            q.pop();

            // Decrease the ticket ka count
            tickets[front]--;

            // Check if we get the time
            if( k == front && tickets[front] == 0){
                return time;
            }

            if(tickets[front]!=0){
                q.push(front);
            }
        }

        return time;
    }

    /*
        Analysis:
        Time Complexity : O(n*m)
        Sapce Complexity : O(n)
    */    

    // Brute Force by using the array
    int solution2(vector<int>&tickets, int k){
        int len = tickets.size();

        int time = 0;

        if(tickets[k] == 1){
            return k+1;
        }

        while(tickets[k]>0){
            for(int i = 0;i<len;i++){
                if(tickets[i]!=0){
                    tickets[i]--;
                    time++;
                }

                if(tickets[k] == 0){
                    return time;
                }
            }
        }

        return time;
    }

    /*
        Analysis:
        Time Complexity : O(n*m)
        Sapce Complexity : O(1)
    */

    // Single pass solution
    int solution3(vector<int>&tickets, int k){
        int time = 0;
        int len = tickets.size();

        for(int i = 0;i<len;i++){
            if(i<=k){
                time+=min(tickets[i],tickets[k]);
            }else{
                time+=min(tickets[k]-1,tickets[i]);
            }
        }
        return time;
    } 

    /*
        Analysis:
        Time Complexity : O(N)
        Space Complexity : O(1)
    */    


    int timeRequiredToBuy(vector<int>& tickets, int k) {
        return solution3(tickets,k);
    }
};

