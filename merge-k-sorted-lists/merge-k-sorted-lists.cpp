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
        auto cmp=[](ListNode* a,ListNode* b){
            return a->val>b->val;
        };
        priority_queue<ListNode*,vector<ListNode*>,decltype(cmp)> q(cmp);
        for(auto list:lists){
            if(list) q.push(list);
        }
        
        ListNode* dummy=new ListNode(),*l=dummy;
        while(!q.empty()){
            l->next=q.top();q.pop();
            l=l->next;
            if(l->next) q.push(l->next);
        }
        return dummy->next;
    }
    
    
};