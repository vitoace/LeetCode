#include <iostream>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

ListNode* swapPairs(ListNode* head) {
  if (!head || !head->next) return head;
  ListNode *pre = NULL;
  ListNode *res = head->next;
  while (head && head->next) {
    ListNode* next = head->next;
    head->next = next->next;
    next->next = head;
            
    if (pre) {
      pre->next = next;
    }
    pre = head;
            
    head = head->next;
  }
  return res;
}

int main() {
  ListNode *test = new ListNode(2);
  test->next = new ListNode(5);
  test->next->next = new ListNode(3);
  test->next->next->next = new ListNode(4);
  test->next->next->next->next = new ListNode(6);
  test->next->next->next->next->next = new ListNode(2);
  test->next->next->next->next->next->next = new ListNode(2);

  ListNode *head = swapPairs(test);
  while(head) {
    cout << head->val << ' ';
    head = head->next;
  }
  cout << endl;
}
