/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:

    vector<vector<int>> solution1(int m, int n, ListNode *head)
    {
        vector<vector<int>>matrix(m, vector<int>(n,-1));

        int top = 0;
        int bottom = m-1;
        int left = 0;
        int right = n-1;

        int id = 0;


        while(top <= bottom && left <= right)
        {
            // Traverse from the left to right (means rows constant)
            if(id == 0)
            {
                for(int i = left; head != nullptr && i <= right ; ++i)
                {
                    matrix[top][i] = head->val;
                    head = head->next;
                }
                ++top;
            }
            // top to bottom (row changes col constant)
            else if(id == 1)
            {
                for(int i = top; head != nullptr && i <= bottom; ++i)
                {
                    matrix[i][right] = head->val;
                    head = head->next;
                }

                --right;
            }
            // Right to left (row constant col changing)
            else if(id == 2)
            {
                for(int i = right; head !=nullptr && i >= left; --i)
                {
                    matrix[bottom][i] = head->val;
                    head = head->next;
                }

                --bottom;
            }
            // Bottom to top (row changing col constant)
            else if(id == 3)
            {
                for(int i = bottom ; head != nullptr && i >=top; --i)
                {
                    matrix[i][left] = head->val;
                    head = head->next;
                }
                ++left;
            }

            // update the id
            id = (id + 1)%4;
        }

        return matrix;
    }
    /*
        Analysis:
        Time Complexity : O(M*N)
        Space Complexity : O(1)
    */    


    vector<vector<int>> spiralMatrix(int m, int n, ListNode* head) {
        return solution1(m,n,head);
    }
};