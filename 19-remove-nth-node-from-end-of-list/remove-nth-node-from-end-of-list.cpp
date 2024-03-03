// /**
//  * Definition for singly-linked list.
//  * struct ListNode {
//  *     int val;
//  *     ListNode *next;
//  *     ListNode() : val(0), next(nullptr) {}
//  *     ListNode(int x) : val(x), next(nullptr) {}
//  *     ListNode(int x, ListNode *next) : val(x), next(next) {}
//  * };
//  */
// class Solution {
// public:

//     int getLengthOfLinkedList(ListNode *head){
//         int len = 0;
//         while(head!=NULL){
//             len++;
//             head = head->next;
//         }

//         return len;
//     }


//     ListNode* removeNthFromEnd(ListNode* head, int n) {
//         int len = getLengthOfLinkedList(head);

//         if(len == n){
//             ListNode *temp = head->next;
//             delete (head);
//             return temp;
//         }

//         ListNode * temp = head;
//         ListNode *prev = NULL; 

//         int node_to_be_deleted = len - n;

//         for(int i = 0;i<node_to_be_deleted;i++){
//             prev = temp; 
//             temp = temp->next;
//         }

//         // now delete
//         prev->next = temp->next;

//         // delete node
//         delete (temp);
//         return head;
//     }
// };

// /*
//     Analysis:
//     Time Complexity : O(n)
//     Space Complexity : O(1)
// */    


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
        // Move temp n node ahead
        ListNode *temp = head;
        ListNode *prev = head;

        for(int i = 0;i<n;i++){
            temp = temp->next;
        }

        if(temp == NULL){
            ListNode *result = head->next;
            delete (head);
            return result;
        }

        while(temp!=NULL && temp->next!=NULL){
            prev = prev->next;
            temp = temp->next;
        }

        ListNode * delNode = prev->next;
        prev->next = prev->next->next;
        delete (delNode);

        return head;
    }
};

/*
    Analysis:
    Time Complexity : O(n)
    Space Complexity : O(1)
*/    