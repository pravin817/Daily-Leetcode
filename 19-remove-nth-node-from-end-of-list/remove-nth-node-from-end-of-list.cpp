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

    int getLengthOfLinkedList(ListNode *head){
        int len = 0;
        while(head!=NULL){
            len++;
            head = head->next;
        }

        return len;
    }


    ListNode* removeNthFromEnd(ListNode* head, int n) {
        int len = getLengthOfLinkedList(head);

        if(len == n){
            ListNode *temp = head->next;
            delete (head);
            return temp;
        }

        ListNode * temp = head;
        ListNode *prev = NULL; 

        int node_to_be_deleted = len - n;

        for(int i = 0;i<node_to_be_deleted;i++){
            prev = temp; 
            temp = temp->next;
        }

        // now delete
        prev->next = temp->next;

        // delete node
        delete (temp);
        return head;
    }
};

/*
    Analysis:
    Time Complexity : O(n)
    Space Complexity : O(1)
*/    