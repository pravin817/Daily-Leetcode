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
    bool isPalindrome(ListNode* head) {
        
        // Brute force ---> Traverse the linkedList and store the values in the vector
        vector<int>v;

        ListNode *temp = head;
        while(temp!=NULL){
            v.push_back(temp->val);
            temp = temp->next;
        }

        int high = v.size()-1;
        int low = 0;
        while(low<=high){
            if(v[low++]!=v[high--]){
                return false;
            }
        }
        return true;

        /*  
            Analysis:
            Time Complexity :O(n)
            Space Complexity : O(n)
        */    
    }
};