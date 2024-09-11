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

    ListNode* insertGreatestCommonDivisors(ListNode* head) {
        
        // Check if the linkedList is empty or contains one element
        if(head == nullptr || head->next == nullptr)
            return head;

        // Traverse the linkedList and do simulation as mentioned in the problem statement
        ListNode *curr = head;

        while(curr != nullptr && curr->next != nullptr)
        {
            //  1. Get the first number from the linkedList
            int num1 = curr->val;

            // 2. Get the second number from the linkedList
            int num2 = curr->next->val;

            // 3. Find the GCD
            int num = GCD(num1,num2);

            // 4. Create the Node
            ListNode *newNode = new ListNode(num);

            // 5. Change the linkage of links
            newNode->next = curr->next;

            curr->next = newNode;

            // Move curr
            curr = newNode->next;
        }
        return head;
    }
};