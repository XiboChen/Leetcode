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
    void reorderList(ListNode* head) {
        ListNode* slow=head;
        ListNode* fast=head;
        while(fast->next&&fast->next->next){
            slow=slow->next;
            fast=fast->next->next;
        }
        //此时slow在中点
        ListNode* new_head=slow->next;
        slow->next=NULL;
        //翻转后半部分
        ListNode* pre=NULL;
        ListNode* cur=new_head;
        while(cur){
            ListNode* next=cur->next;
            cur->next=pre;
            pre=cur;
            cur=next;
        }
        //在这之后，pre处在头节点，而cur因为还存在所以走到了next的位置，是NULL了
        while(head&&pre){
            ListNode* next=head->next;//记录一下这个next
            head->next=pre;
            pre=pre->next;
            head->next->next=next;
            head=next;
        }
    }
};