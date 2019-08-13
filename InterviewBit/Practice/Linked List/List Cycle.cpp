/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
ListNode* Solution::detectCycle(ListNode* A) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    ListNode *a = A, *b = A;
    // a = a->next;
    // if(b->next == NULL)
    //     return NULL;
    b = b->next;
    while(a != b) {
        if(b == NULL || b->next == NULL)
            return NULL;
        a = a->next;
        b = b->next->next;
    }
    if(a == a->next)
        return a;
    ListNode *temp = a->next;
    int c = 1;
    while(temp != a) {
        temp = temp->next;
        ++c;
    }
    ListNode *start = A;
    temp = start;
    while(c--) {
        temp = temp->next;
    }
    
    while(start != temp) {
        start = start->next;
        temp = temp->next;
    }
    return temp;
}