/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
ListNode* Solution::reverseBetween(ListNode* A, int B, int C) {
    if(A->next == NULL)
        return A;
    ListNode *pre = NULL, *agla = NULL, *trav = NULL, *start = A;
    ListNode *head = NULL, *left = NULL;
    for(int i=1; start != NULL; i++, start = start->next) {
        if(i<B) {
            pre = start;
            left = start;
        } else if (i == B) {
            pre = start;
            head = start;
            trav = pre->next;
        } else if(i>B && i<=C) {
            agla = trav->next;
            trav->next = pre;
            pre = trav;
            trav = agla;
        } else if(i == C+1) {
            head->next = trav;
            if(left == NULL)
                return pre;
            left->next = pre;
            return A;
        }
    }
}
