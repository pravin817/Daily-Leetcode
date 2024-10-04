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

    // Function that build the linkedList from the vector
    ListNode* BuildLinkedList(const std::vector<int>& nums)
    {
        ListNode* curr = nullptr;
        ListNode* head = nullptr;

        int n = nums.size();

        for(int i = 0; i < n; ++i)
        {
            // 1. Create the node
            ListNode *currentNewNode = new ListNode(nums[i]);

            if(curr == nullptr)
            {
                // If the node to be create is the first node then the curr will be point to the currentNewNode and head is pointing to the curr
                curr = currentNewNode;
                head = curr;
            }
            else
            {
                curr->next = currentNewNode;
                curr = curr->next;
            }
        }
        return head;
    }

    // Function that swaps the two numbers
    void swap(int &a, int &b)
    {
        int temp = a;
        a = b;
        b = temp;
    }

    // Function that reverse the array
    void ReverseArray(std::vector<int> &nums)
    {
        int low = 0;
        int high = nums.size()-1;

        while(low < high)
        {
            swap(nums[low], nums[high]);

            ++low;
            --high;
        }
    }

    ListNode* solution1(ListNode* head)
    {
        std::vector<int>linkedListToVec;
        // edge case
        if(head == nullptr)
            return head;

        // 1. Take out the values from the linkedList
        ListNode* curr = head;
        while(curr!=nullptr)
        {
            // Take out the value from the linkedlist into the vector
            linkedListToVec.push_back(curr->val);

            // Move to the next node
            curr = curr->next;
        }

        // 2. Reverse the elements from the vector
        ReverseArray(linkedListToVec);

        // 3. Build the linkedList and return the head
        return BuildLinkedList(linkedListToVec);
    }

    ListNode* reverseList(ListNode* head) {
        return solution1(head);
    }
};