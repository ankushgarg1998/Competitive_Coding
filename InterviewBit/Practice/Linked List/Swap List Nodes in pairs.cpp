/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
ListNode* Solution::swapPairs(ListNode* A) {
    ListNode *temp = A;
    if(A->next != NULL) {
        A = temp->next;
        while(temp != NULL && temp->next != NULL) {
            ListNode *bro = temp->next->next;
            temp->next->next = temp;
            temp->next = bro;
            if(bro != NULL && bro->next != NULL) {
                temp->next = bro->next;
                temp = bro;
            } else
                break;
        }
    }
    return A;
}
