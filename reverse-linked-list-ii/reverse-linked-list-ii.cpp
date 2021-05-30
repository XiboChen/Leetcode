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
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        ListNode *dummy=new ListNode(),*pre=dummy;
        dummy->next=head;
        for(int i=0;i<left-1;i++)
            pre=pre->next;  //让pre到left左边的位置，后面声明cur对准left
        ListNode* cur=pre->next;
        for(int i=left;i<right;i++){
            ListNode* t=cur->next;
            cur->next=t->next;//让cur指去最后
            t->next=pre->next;//让t next指去最前面（pre一直不变）
            pre->next=t;//让t成为最前面的
        }
        return dummy->next;
    }
};