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
        ListNode *dummy=new ListNode(-1),*pre=dummy,*cur=head;
        dummy->next=head;
        int cnt=1;
        while(cur){
            if(cnt%k==0){
                ListNode *next=cur->next;
                pre=reverse(pre,cur->next);
                cur=pre->next;
            }
            else cur=cur->next;
            cnt++;
        }
        return dummy->next;
    }
    //reverse function
    //传进来的next一直不变，方便最后指向它，pre也不变
    ListNode* reverse(ListNode *pre,ListNode *next){
        ListNode *last=pre->next,*cur=last->next;//设last，会reverse成最后一个
        while(cur!=next){
            //转换完成后，last最后一个，next是next，而cur等于lastnext，正好停止
            last->next=cur->next;//其实是两两翻转
            cur->next=pre->next;
            pre->next=cur;
            cur=last->next;
        }
        return last; //此时last对应的正好是传入前的pre
    }
};