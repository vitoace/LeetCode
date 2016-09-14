#include <iostream>

using namespace std;

struct ListNode {
  int val;
  ListNode *next;
  ListNode(int i) : val(i) {};
};

void printListNode(ListNode* head) {
  while(head) {
    cout << head->val;
    if (head->next) cout << "->";
    head = head->next;
  }
  cout << endl;
}

ListNode* partition(ListNode* head, int x);
int main() {
  ListNode *head = new ListNode(3);
  head->next = new ListNode(1);
  head->next->next = new ListNode(2);
  ListNode *res = partition(head, 3);
  printListNode(res);
  return 0;
}

ListNode* partition(ListNode* head, int x) {
  if (!head || !head->next) return head;
        
  ListNode *p1 = NULL, *p2 = head;
  if (head->val < x)
    while (p2 && p2->val < x) {
      p1 = p2;
      p2 = p2->next;
    }
        
  if (!p2) return head;
  while (p2) {
    if (p2->next && p2->next->val < x) {
      ListNode *temp = p2->next;
      p2->next = p2->next->next;
      if (!p1) {
	temp->next = head;
	head = temp;
	p1 = temp;
      } else {
	temp->next = p1->next;
	p1->next = temp;
	p1 = temp;
      }
    }
    else p2 = p2->next;
  }
  return head;
}
