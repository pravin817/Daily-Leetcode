/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode() {}
 *     TreeNode(int val) { this.val = val; }
 *     TreeNode(int val, TreeNode left, TreeNode right) {
 *         this.val = val;
 *         this.left = left;
 *         this.right = right;
 *     }
 * }
 */
class Solution {
    
    /**
     * Checks if the root node's value is equal to the sum of its left and right child values.
     *
     * @param root The root node of the binary tree
     * @return true if root.val == left.val + right.val; false otherwise
     * @author Pravin Mhaske
     * @date   29/06/2025
     */

    private boolean isRootEqualsToLeftAndRightNode(TreeNode root) {
        if (root != null && root.left != null && root.right != null) {
            return root.val == (root.left.val + root.right.val);
        }
        
        return false;
    }

    /*
        Analysis:
        Time Complexity  : O(1)
        Space Complexity : O(1)
    */

    public boolean checkTree(TreeNode root) {
        return isRootEqualsToLeftAndRightNode(root);
    }
}