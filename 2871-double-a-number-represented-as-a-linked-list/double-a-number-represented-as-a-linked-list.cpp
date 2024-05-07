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

    ListNode* reverseLL(ListNode *head){

        if(head == NULL || head->next == NULL){
            return head;
        }

        ListNode *curr = head;
        ListNode *prev = NULL;

        while(curr!=NULL){
            ListNode *nbr = curr->next;
            curr->next = prev;
            prev = curr;
            curr = nbr;
        }

        return prev;
    }


    ListNode* doubleIt(ListNode* head) {
        
        ListNode *reversedList = reverseLL(head);
        ListNode* curr = reversedList;
        ListNode* lastNode = NULL;

        int carry = 0;

        while(curr!=NULL){
            int sum = curr->val*2 + carry;
            carry = sum / 10;
            int digit = sum % 10;
            curr->val = digit;
            lastNode = curr;
            curr = curr->next;
        }

        if(carry>0){
            ListNode *temp = new ListNode(carry);
            lastNode->next = temp;
        }

        ListNode* result = reverseLL(reversedList);

        return result;
    }
};

/*
    Analysis:
    Time Complexity : O(N)
    Space Complexity : O(1)
*/    