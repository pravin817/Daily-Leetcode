/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
public:

    void solve(Node *root, vector<int>&answer)
    {
        if(root == NULL)
            return;

        // Traverse the all children nodes
        for(int i = 0; i < root->children.size(); ++i)
        {
            solve(root->children[i], answer);
        }
        answer.push_back(root->val);
    }

    /*
        Analysis:
        Time Complexity : O(N)
        Sapce Complexity : O(N)
    */    

    vector<int> postorder(Node* root) {
        vector<int>answer;
        solve(root, answer);
        return answer;
    }
};

