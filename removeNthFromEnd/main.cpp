#include <iostream>

using namespace std;

struct ListNode {
  ListNode* next;
  int val;
  ListNode(){};
  ListNode(int v):val(v), next(NULL){};
};
ListNode *removeNthFromEnd(ListNode *head, int n);
int main() {
  // insert your code here
  ListNode* head = new ListNode(1);
  ListNode* cur = head;
  for (int i = 2; i < 10; i++) {
    ListNode* temp = new ListNode(i);
    cur->next = temp;
    cur = cur->next;
  }
  head = removeNthFromEnd(head, 4);
  while(head) {
    cout << head->val << ' ';
    head = head->next;
  }
  cout << endl;
  return 0;
}

ListNode *removeNthFromEnd(ListNode *head, int n) {
  if (head == NULL || head->next == NULL)
    return NULL;
  ListNode* first = head;
  ListNode* second = head;
  for (int i = 0; i < n; i++)
    first = first->next;
  ListNode* pre = head;
  while(first) {
    first = first->next;
    pre = second;
    second = second->next;
  }
  if (pre == second) {
    head = head->next;
  }
  else
    pre->next = pre->next->next;
  delete second;
  return head;
}
