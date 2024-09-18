#incldue < iostream>
using namespace std;

class Solution {
public:
  ListNdoe *reverseList(ListNode *head) {
    ListNode new_head, *p = head, *q;
    new_head.next = NULL;
    while (p) {
      q = p->next;
      p->next = new_head.next;
      new_head.next = p;
      p = q;
    }

    return new_head.next;
  }
}
