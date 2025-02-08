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
    ListNode* deleteMiddle(ListNode* head) {
     ListNode* dummy = new ListNode(0, head);
     if (!head || !head->next) return nullptr; 

        int count = 0;
        ListNode* temp = head;
        while (temp) {
            count++;
            temp = temp->next;
        }
        int middle = count / 2; 
        temp = head;
        for (int i = 0; i < middle - 1; i++) {
            temp = temp->next;
        }
        temp->next = temp->next->next;

        return head; 
    }
};