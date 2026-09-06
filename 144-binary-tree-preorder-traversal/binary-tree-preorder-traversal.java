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

    // Recursive solution
    private void preOrder(TreeNode root, List<Integer> result) {
        if (root == null) {
            return;
        }

        result.add(root.val);
        preOrder(root.left, result);
        preOrder(root.right, result);
    }

    /*
        Analysis:
            Time Complexity  : O(n) , Where n is the number of the nodes in the tree
            Space Complexity : O(n)
    */

    // Iterative solution using stack
    private List<Integer> preOrderIterative(TreeNode root) {

        List<Integer> result = new ArrayList<>();

        if (root == null) {
            return result;
        }

        // Create the stack
        Deque<TreeNode> stack = new ArrayDeque<>();
        stack.push(root);

        while(!stack.isEmpty()) {
            TreeNode node = stack.pop();

            result.add(node.val);

            if (node.right != null) {
                stack.push(node.right);
            }

            if (node.left != null) {
                stack.push(node.left);
            }
        }

        return result;
    }

    /*
        Analysis:
            Time Complexity  : O(n)
            Space Complexity : O(n)
    */

    public List<Integer> preorderTraversal(TreeNode root) {
        // List<Integer> result = new ArrayList<>();
        // preOrder(root, result);
        // return result;

        return preOrderIterative(root);
    }
}