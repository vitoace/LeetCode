#include <iostream>

using namespace std;

struct ListNode {
  ListNode* next;
  int val;
  ListNode(int val) : val(val) {}
  ListNode(){};
};

void reorderList(ListNode *head);
int main() {
  ListNode *head = new ListNode(1);
  head->next = new ListNode(2);
  head->next->next = new ListNode(3);
  head->next->next->next = new ListNode(4);
  reorderList(head);
  while (head != 0) {
    cout << head->val << ' ';
    head = head->next;
  }
  cout << endl;
  return 0;
}

ListNode *cur = 0;
void reorder(ListNode* mid);
void reorderList(ListNode *head) {
  if (head == 0 || head->next == 0 || head->next->next == 0)
    return;
  ListNode *mid = head, *fast = head;
  while(fast != 0 && fast->next != 0) {
    mid = mid->next;
    fast = fast->next->next;
  }

  cur = head;
  reorder(mid);
  mid->next = 0;
}
    
void reorder(ListNode* mid) {
  if (mid->next != 0)
    reorder(mid->next);

  ListNode* next = cur->next;
  cur->next = mid;
  cur = next;
  mid->next = next;
}
