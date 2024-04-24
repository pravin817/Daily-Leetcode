class Solution {
public:
    int tribonacci(int n) {

        // Define the base cases

        if(n == 0)
            return 0;

        if(n == 1 || n == 2)
            return 1;
            
        // Now we can optimise the space to O(1)
        // Let's see

        // We need to define four variables

        int a = 0,
            b = 1,
            c = 1,
            d = 0;


        // Now iterate throgth the loop and change the values

        for(int i =3; i<=n;i++)
        {
            d = a+b+c;
            a = b;
            b = c;
            c = d;
        }   

        return c;  

    }
};

/* 
    Analysis:
    Time Complexity : O(n)
    Space Complexity : O(1)
*/    