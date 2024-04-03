class Solution {
public:
    string countAndSay(int n) {
        
        // Base case 
        if(n == 1){
            return "1";
        }

        // Recursive call 
        string say = countAndSay(n-1);

        // Small Task ---> Processing
        string ans = "";

        for(int i = 0;i<say.length();i++){
            int count = 1;
            char ch = say[i];

            // find the count
            while(i<say.length()-1 && say[i] == say[i+1]){
                count++;
                i++;
            }

            // ans += to_string(count)+ ""+(ch);

            ans += to_string(count) + (1,ch);
        }

        return ans;
    }
};