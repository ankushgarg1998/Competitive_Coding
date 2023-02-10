/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
ListNode* Solution::partition(ListNode* A, int B) {
    ListNode *start = A, *ans = NULL, *head = NULL;
    while(start != NULL) {
        if(start->val < B) {
            if(ans == NULL) {
                ans = new ListNode(start->val);
                head = ans;
            } else {
                ans->next = new ListNode(start->val);
                ans = ans->next;
            }
        }
        start = start->next;
    }
    start = A;
    while(start != NULL) {
        if(start->val >= B) {
            if(ans == NULL) {
                ans = new ListNode(start->val);
                head = ans;
            } else {
                ans->next = new ListNode(start->val);
                ans = ans->next;
            }
        }
        start = start->next;
    }
    return head;
}
