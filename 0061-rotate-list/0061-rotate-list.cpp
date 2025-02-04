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
    ListNode* rotateRight(ListNode* head, int k) {
    if (!head || !head->next) {
            return head;
        }
        std::deque<ListNode*> dq;
        ListNode* cur = head;
        while (cur) {
            dq.push_back(cur);
            cur = cur->next;
        }

        int n = dq.size();
        k %= n; 
        if (k == 0) {
            return head;
        }
        for (int i = 0; i < k; i++) {
            dq.push_front(dq.back());
            dq.pop_back();
        }
        head = dq.front();
        for (int i = 0; i < n - 1; i++) {
            dq[i]->next = dq[i + 1];
        }
        dq.back()->next = nullptr; 

        return head;    
    }
};