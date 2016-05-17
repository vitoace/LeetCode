#include <iostream>
#include <stack>
using namespace std;

struct ListNode {
  int val;
  ListNode *next;
  ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
  ListNode* reverseKGroup(ListNode* head, int k) {
    stack<ListNode*> stk;
    ListNode* begin = head;
    bool flag = true;
    ListNode* last = NULL;
    while (begin != NULL) {
      for (int i = 0; i < k; i++) {
	if (begin == NULL) return head;
	stk.push(begin);
	begin = begin->next;
      }
            
      ListNode* cur = begin;

      while (!stk.empty()) {
	ListNode* tmp = stk.top();
	if (last != NULL) {
	  last->next = tmp;
	  last = NULL;
	}
	if (flag) {
	  head = tmp;
	  flag = false;
	}
	stk.pop();
	if (stk.empty()) {
	  tmp->next = cur;
	  last = tmp;
	}
	else
	  tmp->next = stk.top();
      }
    }
    return head;
  }

  void printLinkList(ListNode* begin) {
    ListNode* head = begin;
    cout << "list: ";
    while (head != NULL) {
      cout  << head->val << ' ';
      head = head->next;
    }
    cout << endl;
  }
};

void printLinkList(ListNode* begin) {
  ListNode* head = begin;
  while (head != NULL) {
    cout << head->val << ' ';
    head = head->next;
  }
  cout << endl;
}

int main() {
  Solution s;
  ListNode* head = new ListNode(1);
  // head->next = new ListNode(2);
  // head->next->next = new ListNode(3);
  // head->next->next->next = new ListNode(4);
  head = s.reverseKGroup(head, 2);
  printLinkList(head);
  return 0;
}
