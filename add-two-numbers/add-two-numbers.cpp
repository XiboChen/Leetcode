/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* dummy=new ListNode();
        ListNode* tail=dummy;
        int carry=0;
        while(l1||l2){
            ListNode* cur=new ListNode();
            if(l1){
                cur->val=cur->val+l1->val;
                l1=l1->next;
            }
            if(l2){
                cur->val=cur->val+l2->val;
                l2=l2->next;
            }
            cur->val=cur->val+carry;
            
            carry=cur->val/10;
            cur->val=cur->val%10;
            tail->next=cur;
            tail=tail->next;
        }
        if(carry>0){
            ListNode* t=new ListNode();
            t->val=carry;
            tail->next=t;
            tail=tail->next;
        }
        
        return dummy->next;
    }
};