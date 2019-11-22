/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int sum = 0;
        ListNode *head = NULL;
        ListNode *ptr = NULL;
        ListNode *ptr1 = l1;
        ListNode *ptr2 = l2;
        
        while((ptr1 != NULL) || (ptr2 != NULL)){
            if(ptr1 == NULL) {
                sum += ptr2->val;
                ptr2 = ptr2->next;
            }
            else if(ptr2 == NULL) {
                sum += ptr1->val;
                ptr1 = ptr1->next;
            }
            else {
                sum += ptr1->val + ptr2->val;
                ptr1 = ptr1->next;
                ptr2 = ptr2->next;
            }
            int carry = 0;
            if(sum >= 10) {
                sum -= 10;
                carry = 1;
            }
            ListNode *node = new ListNode(sum);
            // Set the head on the first loop
            if(head == NULL) {
                head = node;
                ptr = node;
            }
            else {
                ptr->next = node;
                ptr = ptr->next;
            }            
            sum = carry;   
        }
        // Check if there is an extra carry
        if(sum != 0) {
            ListNode *node = new ListNode(sum);
            ptr->next = node;
        }
        return head;
    }
};