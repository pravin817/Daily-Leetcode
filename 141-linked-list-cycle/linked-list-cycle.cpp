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

    // Brute force solution : Store the Node in set and check if we get the node again then there is a loop in the LinkedList

    bool solution1(ListNode* head){
        if(head == NULL || head->next == NULL){
            return false;
        }

        unordered_set<ListNode*> s;
        ListNode* curr = head;

        while(curr != NULL){
            if(s.find(curr) != s.end()){
                return true;
            }
            s.insert(curr);
            curr = curr->next;
        }

        return false;
    }

    /*
        Analysis:
        Time Complexity : O(N)
        Space Complexity : O(N)
    */

    // We can optimied the above solution by using the slow and fast pointer

    bool solution2(ListNode* head){
        if(head == NULL || head->next == NULL){
            return false;
        }

        ListNode* slow = head;
        ListNode* fast = head;

        while(fast != NULL && fast->next != NULL){

            // Move the slow pointer by one place
            slow = slow->next;

            // Move the fast pointer by two place
            fast = fast->next->next;

            // Check if the slow and fast pointer pointing to the same node
            if(slow == fast){
                return true;
            }
        }

        return false;
    }

    /*
        Anlysis:
        Time Complexity : O(N)
        Space Complexity : O(1)
    */

    bool hasCycle(ListNode *head) {
        return solution2(head);
    }
};