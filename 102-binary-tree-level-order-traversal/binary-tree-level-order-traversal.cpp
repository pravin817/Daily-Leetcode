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

    // Brute Force solution : By using the queue 
    std::vector<std::vector<int>> solution1(TreeNode* root) {
        std::vector<std::vector<int>> result;

        if(root == nullptr) {
            return result;
        }

        std::queue<TreeNode*> queue;
        queue.push(root);

        while(!queue.empty()) {

            int len = queue.size();
            std::vector<int> level;

            for(int i = 0; i < len; ++i) {
                TreeNode *currentNode = queue.front();
                queue.pop();

                level.push_back(currentNode->val);

                // Explore the left side
                if(currentNode->left != nullptr) {
                    queue.push(currentNode->left);
                }

                if(currentNode->right != nullptr) {
                    queue.push(currentNode->right);
                }
            }
            result.push_back(level);
        }
        return result;
    }

    /*  
        Analysis:
        Time Complexity  : O(N)
        Space Complexity : O(N)
    */
    
    vector<vector<int>> levelOrder(TreeNode* root) {
        return solution1(root);
    }
};