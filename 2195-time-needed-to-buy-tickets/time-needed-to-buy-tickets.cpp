class Solution {
public:
    int timeRequiredToBuy(vector<int>& tickets, int k) {
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
};


/*
    Analysis:
    Time Complexity : O(n*m)
    Sapce Complexity : O(n)
*/    