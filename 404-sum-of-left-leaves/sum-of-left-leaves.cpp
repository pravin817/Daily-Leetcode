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

    // Solution by using the parent Node
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

    //Solution by using the isLeft flag

    int solution2(TreeNode *curr, bool isLeft){
        // Base case
        if(curr == NULL){
            return 0;
        }

        // check if the node is left leaf node
        if(curr->left == NULL && curr->right == NULL && isLeft  == true){
            return curr->val;
        }

        // small calculation + Recursive call
        return solution2(curr->left, true)+solution2(curr->right, false);
    }


    /*
        Analysis:
        Time Complexity : O(N)
        Space Complexity : O(1) //Auxiiliary Space and O(depth of tree) recursion system stack space
    */    

    int sumOfLeftLeaves(TreeNode* root) {
        // return solution1(root,NULL);
        return solution2(root, false);
    }
};