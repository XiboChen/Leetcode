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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        return helper(lists,0,(int)lists.size()-1);
    }
    
    ListNode* helper(vector<ListNode*>& lists,int start,int end){
        if(start>end) return NULL;
        if(start==end) return lists[start];
        int mid=start+(end-start)/2;
        ListNode* l1=helper(lists,start,mid);
        ListNode* l2=helper(lists,mid+1,end);
        return mergeTwoLists(l1,l2);
    }
    
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode* dummy=new ListNode(-1);
        ListNode* cur=dummy;
        while(l1 && l2){
            if(l1->val<l2->val){
                cur->next=l1;
                l1=l1->next;
            }
            else{
                cur->next=l2;
                l2=l2->next;
            }
            cur=cur->next;
        }
        cur->next=l1?l1:l2;
        return dummy->next;
        // if (!l1) return l2;
        // if (!l2) return l1;
        // if (l1->val < l2->val) {
        //     l1->next = mergeTwoLists(l1->next, l2);
        //     return l1;
        // } else {
        //     l2->next = mergeTwoLists(l1, l2->next);
        //     return l2;
        // }
    }
};