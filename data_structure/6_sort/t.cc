class Solution {
public:
  ListNode *sortList(ListNode *head) {
    if (!head || !head->next)
      return head;
    int z = head->val;
    ListNode *h1 = nullptr, *h2 = nullptr, p, q;

    p = head;
    while (p) {
      q = p->next;
      if (p->val <= z) {
        p->next = h1;
        h1 = p;
      } else {
        p->next = h2;
        h2 = p;
      }
      p = q;
    }

    p = sortList(p);
    q = sortList(q);
    ListNode *h = p;
    while (p->next)
      p = p->next;
    p->next = q;
    return h;
  }
};
