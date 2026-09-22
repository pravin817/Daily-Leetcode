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

    /**
     * Counts the total number of nodes in the linked list.
     * Used by the brute-force approach to determine the middle index.
     */
    private int countNodes(ListNode head) {
        int count = 0;

        while (head != null) {
            count++;
            head = head.next;
        }

        return count;
    }

    /*
        Analysis:
            Time Complexity  : O(n), where n is the number of nodes in the linked list
            Space Complexity : O(1)
    */

    /**
     * Brute Force Solution.
     * Step 1: Count the total number of nodes in the list.
     * Step 2: Walk forward total/2 steps from head to land on the middle node.
     *
     * Note: total/2 (integer division) correctly lands on the SECOND middle
     * node when the list length is even, matching the problem's requirement.
     */
    private ListNode bruteForceSolution(ListNode head) {
        // First pass: get the total node count
        int total = countNodes(head);

        // Middle index (0-based) to stop at
        int middle = total / 2;

        // Second pass: advance 'middle' steps from head
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

    /**
     * Two-Pointer (Slow & Fast) Solution — optimal approach.
     *
     * Uses two pointers starting at head:
     *   - slow moves one node at a time.
     *   - fast moves two nodes at a time.
     *
     * Since fast moves twice as fast as slow, by the time fast reaches
     * the end of the list, slow will be positioned exactly at the middle.
     * This also naturally resolves to the SECOND middle node for
     * even-length lists, since fast runs out of room one step early.
     */
    private ListNode middleNodeTwoPointerSolution(ListNode head) {
        if (head == null) {
            return head;
        }

        ListNode slow = head;
        ListNode fast = head;

        while (fast != null && fast.next != null) {
            slow = slow.next;
            fast = fast.next.next;
        }

        return slow;
    }

    /*
        Analysis:
            Time Complexity  : O(n/2) --> O(n)
            Space Complexity : O(1)
    */

    public ListNode middleNode(ListNode head) {
        return middleNodeTwoPointerSolution(head);
    }
}