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
  set<pair<int,ListNode*>> s;
  int cnt;
  ListNode* mergeKLists(vector<ListNode*>& lists) {
    cnt = 0;
    for(auto x: lists){
      s.insert({x->val, x});
    }
    ListNode* head, *p=head;
    while(s.size()){
      p->next = s.begin()->second;
      p = p->next;
      s.erase(s.begin());
      if(p) s.insert({p->val, p});
    }
    return head->next;
  }
};
