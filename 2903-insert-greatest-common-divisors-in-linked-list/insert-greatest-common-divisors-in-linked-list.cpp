/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:

    // Function that finds the GCD of two numbers
    int GCD(int a, int b)
    {
        if(b == 0)
            return a;

        return GCD(b, a%b);    
    }


    // Simple simulation solution by using the iterative method
    ListNode* solution1(ListNode* head)
    {
        // Check if the Linked List is empty or contains a node
        if(head == nullptr || head->next == nullptr)
            return head;

        ListNode* curr = head;

        while(curr->next != nullptr)
        {
            // 1. Find the GCD
            int firstNumber = curr->val;
            int secondNumber = curr->next->val;

            int number = GCD(firstNumber, secondNumber);

            // 2. Create the node
            ListNode *newNode = new ListNode(number);

            // 3. Make the changes in the linkedList links
            newNode->next = curr->next;
            curr->next = newNode;
            curr = newNode->next;
        }    

        return head;
    }

    /*
        Analysis:
        Time Complexity : O(N)
        Space Complexity : O(1)
    */    

    // Same solution by using the recursive approach
    ListNode* solution2(ListNode* head)
    {
        // Base case
        if(head == nullptr || head->next == nullptr)
            return head;

        //  Recursive call
        ListNode* temp = solution2(head->next);

        // Small calculations
        // Create the GCD Node
        ListNode* newNode = new ListNode(__gcd(head->val, head->next->val));

        newNode->next = temp;

        head->next = newNode;

        return head;
    }

    /*
        Analysis:
        Time Complexity : O(N)
        Space Complexity : O(1)  ----> With considering the stack space
    */    

    ListNode* insertGreatestCommonDivisors(ListNode* head) {
        return solution2(head);
    }
};