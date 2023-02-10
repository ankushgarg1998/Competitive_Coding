/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
ListNode* Solution::reverseList(ListNode* A) {
    ListNode *agla=NULL, *pre=NULL, *trav=A;
    while(trav != NULL) {
        agla = trav->next;
        trav->next = pre;
        pre = trav;
        trav = agla;
    }
    return pre;
}
