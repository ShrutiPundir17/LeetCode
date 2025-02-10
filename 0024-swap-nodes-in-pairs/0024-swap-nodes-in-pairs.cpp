
class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
     ListNode dummy(0);  
        dummy.next = head;
        ListNode* prev = &dummy;
        while (head && head->next) {
            ListNode* first = head;
            ListNode* second = head->next;
            first->next = second->next;
            second->next = first;
            prev->next = second;
            prev = first;
            head = first->next;
        }
        
        return dummy.next;  
    }
};