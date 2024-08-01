class Solution {
public:

    int solution1(vector<string>&details){
        int seniorCitizenCount = 0;
        int passengerCount = details.size();

        // Traverse the details
        for(int i = 0; i < passengerCount; ++i){
            string str = details[i];

            int age = 0;

            age = age * 10 + (int)(str[11] - '0');
            age = age * 10 + (int)(str[12] - '0');

            cout<<"Age : "<<age<<endl;
            if(age > 60){
                seniorCitizenCount++;
            }
        }

        return seniorCitizenCount;
    }

    /*
        Analysis:
        Time Complexity : O(N)
        Space Complexity : O(1)
    */    

    int countSeniors(vector<string>& details) {
        return solution1(details);
    }
};