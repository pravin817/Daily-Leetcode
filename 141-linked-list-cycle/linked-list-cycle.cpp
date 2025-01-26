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

    bool hasCycle(ListNode *head) {
        return solution1(head);
    }
};