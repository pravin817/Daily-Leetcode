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

    int solution1(TreeNode*curr, TreeNode *parent){

        if(curr == NULL){
            return 0;
        }

        // leaf node
        if(curr->left == NULL && curr->right == NULL){
            // check if it is left leaf node
            if(parent!=NULL && parent->left == curr){
                return curr->val;
            }
        }

        // recursive call
        int left = solution1(curr->left,curr);
        int right = solution1(curr->right, curr);

        // small calculation
        return left+right;
    }

    /*
        Analysis:
        Time Complexity : O(N)
        Space Complexity :O(1)  // Auxiiliary Space and O(depth of tree) recursion system stack space
    */    

    int sumOfLeftLeaves(TreeNode* root) {
        return solution1(root,NULL);
    }
};