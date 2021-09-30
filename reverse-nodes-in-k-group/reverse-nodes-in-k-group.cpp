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
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* dummy=new ListNode(0);
        dummy->next=head;
        int len=0;
        while(head){
            len++;
            head=head->next;
        }
        ListNode* pre=dummy;
        for(int l=0;l+k<=len;l+=k){
            ListNode* cur=pre->next;
            ListNode* nxt=cur->next;
            for(int i=1;i<k;++i){
                cur->next=nxt->next;
                nxt->next=pre->next;
                pre->next=nxt;
                nxt=cur->next;
            }
            pre=cur;
        }
        
        return dummy->next;
    }
};