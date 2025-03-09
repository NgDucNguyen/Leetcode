/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
 struct ListNode *tmp1 = NULL;
 void check(struct ListNode *tmp,bool *result){
    if(tmp==NULL) return;
    check(tmp->next,result);
    if(tmp1->val != tmp->val){
        *result = false;
        return;
    }
    tmp1 = tmp1->next;
 }
bool isPalindrome(struct ListNode* head) {
    tmp1 = head;
    struct ListNode *tmp = head;
    bool result = true;
    check(tmp,&result);
    return result;
}