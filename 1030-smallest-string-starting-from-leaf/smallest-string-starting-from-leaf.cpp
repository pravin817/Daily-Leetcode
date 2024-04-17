/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:

    string result = "";

    void dfs(TreeNode *root, string curr){

        // Base case
        if(root == NULL){
            return;
        }

        // Small Calculation
        curr = char(root->val + 'a') + curr;  // If this time is ignored

        // If the node is left node
        if(root->left == NULL && root->right == NULL){
            if(result == "" || result > curr){
                result = curr;
            }

            return;
        }

        // Recursive call
        dfs(root->left,curr);
        dfs(root->right,curr);        
    }

    /*
        Analysis:
        Time Complexity : O(n)   ---> n is the number of the nodes in the tree
        Space Complexity : O(n)  ---> Height of the tree
    */


    string smallestFromLeaf(TreeNode* root) {
        dfs(root,"");
        return result;
    }
};