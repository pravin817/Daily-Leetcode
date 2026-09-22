/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode() {}
 *     ListNode(int val) { this.val = val; }
 *     ListNode(int val, ListNode next) { this.val = val; this.next = next; }
 * }
 */
class Solution {

    // Function used to calculate the total number of the nodes in the linked List
    private int countNodes(ListNode head) {
        int count = 0;

        // Base case
        if (head == null) {
            return 0;
        }

        while(head != null) {
            count++;
            head = head.next;
        }

        return count;
    }

    /*
        Analysis:
            Time Complexity  : O(n), Where n is the number of the nodes in the linked list
            Space Complexity : O(1)
    */

    // Brute Force Solution 
    // Find the total number of the node in the LinkedList and return the node present at ceil(total node / 2)
    private ListNode BruteForceSolution(ListNode head) {
        int total = countNodes(head);
        int middle = total / 2;

        for (int i = 0; i < middle; i++) {
            head = head.next;
        }

        return head;
    }

    /*
        Analysis:
            Time Complexity  : O(n) + O(n/2) = O(n)
            Space Complexity : O(1)
    */

    public ListNode middleNode(ListNode head) {
        return BruteForceSolution(head);
    }
}