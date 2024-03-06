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

    // solution using the Hash Table
    bool hasCycle(ListNode *head) {
        unordered_set<ListNode*>visited_nodes;

        ListNode* currentNode = head;

        // Traverse the linked List
        while(currentNode != nullptr){

            // check if the currentNode is found in the hash Table
            if(visited_nodes.find(currentNode)!=visited_nodes.end()){
                return true;
            }

            // if the currentNode is not in the hash Table then insert it into the hash table
            visited_nodes.insert(currentNode);

            //move to the next node
            currentNode = currentNode->next;
        }

        return false; // if we get null
    }
};


/*
    Analysis:
    Time Complexity : O(n)
    Space Complexity : O(n)
*/    