/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    bool hasCycle(ListNode *head) {
        
        //check for the base case 
        if(head == NULL || head->next == NULL){
            return false;
        }

        // use the slow and fast pointer approach
        ListNode *slow = head;
        ListNode *fast = head;

        while(fast!=NULL && fast->next!=NULL){

            // move the slow and fast pointers
            slow = slow->next;
            fast = fast->next->next;

            if(slow == fast){
                return true;
            }
        }

        return false;
    }
};