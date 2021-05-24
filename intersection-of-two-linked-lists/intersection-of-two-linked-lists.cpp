/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        while(headA){
            ListNode* b=headB;
            while(b){
                if(b==headA)
                    return b;
                b=b->next;
            }
            headA=headA->next;
        }
        return NULL;
    }
};