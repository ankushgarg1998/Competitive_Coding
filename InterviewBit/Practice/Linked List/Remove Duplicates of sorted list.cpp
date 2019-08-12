/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
ListNode* Solution::deleteDuplicates(ListNode* A) {
    ListNode *ans = new ListNode(A->val);
    int pre = A->val;
    ListNode *temp = ans;
    while(A->next != NULL) {
        A = A->next;
        if(A->val != pre) {
            temp->next = new ListNode(A->val);
            pre = A->val;
            temp = temp->next;
        }
    }
    return ans;
}
