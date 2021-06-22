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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        //双指针，fast先移动n，再移动fast和slow，这样slow到最后就是要删除的
        if(!head->next) return NULL;
        ListNode* slow=head, *fast=head;
        for(int i=0;i<n;i++) fast=fast->next;
        if(!fast) return head->next;
        while(fast->next){
            slow=slow->next;
            fast=fast->next;
        }
        
        //让slow临时变成指向删除点的pre
        slow->next=slow->next->next;
        //cout<<slow->val<<" "<<fast->val;
        return head;
    }
};