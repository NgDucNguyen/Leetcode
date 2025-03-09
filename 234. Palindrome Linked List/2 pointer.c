/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
 // dem so phan tu cua danh sach
 int count(struct ListNode *s){
    int cnt = 0;
    while(s!=NULL){
       cnt++;
       s = s->next;
    }
    return cnt;
}
bool isPalindrome(struct ListNode* head){
   if(head == NULL || head->next == NULL) return true;
   int n = count(head),j=n/2;
   struct ListNode *ptr1 = head;
   struct ListNode *ptr2 = head;
   // luu phan dau dnah sach vao arr
   while(j--){
       ptr1 = ptr1->next->next;
       ptr2 = ptr2->next;
   }
   
   if(n%2!=0){
       ptr2 = ptr2->next; // neu so luong la le thi bo qua phan tu giua
   }

   // dao nguoc lua sau danh sach
   struct ListNode *prev = NULL,*next = NULL;
   while(ptr2!=NULL){
       next = ptr2->next;
       ptr2->next = prev;
       prev = ptr2;
       ptr2 = next;
   }

   // sao sanh 2 nuwa
   struct ListNode *left = head,*right = prev;
   while(right!=NULL){
       if(left->val != right->val){
           return false;
       }
       left = left->next;
       right = right->next;
   }
   return true;
}