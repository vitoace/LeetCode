#include <iostream>

using namespace std;

struct ListNode {
  int val;
  ListNode* next;
  ListNode(int val) : val(val), next(0) {}
};

void printList(ListNode *head);
ListNode *insertionSortList(ListNode *head);

int main() {
  ListNode* input = new ListNode(4);
  input->next = new ListNode(2);
  input->next->next = new ListNode(1);
  input->next->next->next = new ListNode(3);
  ListNode* res = insertionSortList(input);
  printList(res);
  return 0;
}

ListNode *insertionSortList(ListNode *head) {
  if (head == 0)
    return head;
  ListNode *inserted = head;
  head = head->next;
  inserted->next = 0;
  int count = 0;
  while (head != 0) {
    count++;
    printList(inserted);
    ListNode *toInsert = head;
    head = head->next;
    if (inserted->val >= toInsert->val) { // insert in the head;
      toInsert->next = inserted;
      inserted = toInsert;
    }
    else {
      bool flag = false;
      ListNode *cur = inserted;
      while(cur->next != 0) {
	if (cur->next->val >= toInsert->val) {
	  ListNode *next = cur->next;
	  cur->next = toInsert;
	  toInsert->next = next;
	  flag = true;
	  break;
	}
	cur = cur->next;
      }
      if (!flag) {
	cur->next = toInsert;
	toInsert->next = 0;
      }
    }
  }
  return inserted;
}

void printList(ListNode *head) {
  while(head != 0) {
    cout << head->val << ' ';
    head = head->next;
  }
  cout << endl;
}
