/**
 * Definition for singly-linked list.
 * class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode(int x) {
 *         val = x;
 *         next = null;
 *     }
 * }
 */
public class Solution {

    // Let's write the same code in JAVA
    private boolean hasCycle1(ListNode head){
        if(head == null || head.next == null){
            return false;
        }

        HashSet<ListNode> set = new HashSet<ListNode>();
        ListNode current = head;

        while(current != null){

            // We found the node in the set
            if(set.contains(current)){
                return true;
            }

            set.add(current);
            current = current.next;
        }

        return false;
    }

    /*
        Analysis:
        Time Complexity  : O(N)
        Space Complexity : O(N)
    */

    // Optimization : We can optimied the above solution by using the slow and fast pointer approach

    private boolean hasCycle2(ListNode head){
        if(head == null || head.next == null) {
            return false;
        }


        ListNode slow = head;
        ListNode fast = head;

        while(fast != null && fast.next != null){

            slow = slow.next;
            fast = fast.next.next;

            if(slow == fast){
                return true;
            }
        }

        return false;
    }

    /*
        Analysis:
        Time Complexity  : O(N)
        Space Complexity : O(1)
    */

    public boolean hasCycle(ListNode head) {
        return hasCycle2(head);
    }
}