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
        auto cmp=[](ListNode* a,ListNode* b){ return a->val>b->val;};
        priority_queue<ListNode*,vector<ListNode*>,decltype(cmp)> q(cmp);
        for(auto list:lists){
            while(list){
                q.push(list);
                list=list->next;
            }
        }
        ListNode * dummy=new ListNode();
        ListNode * l=dummy;
        while(!q.empty()){
            cout<<q.top()->val<<endl;
            l->next=new ListNode(q.top()->val);
            q.pop();
            l=l->next;
        }
        return dummy->next;
    }
};