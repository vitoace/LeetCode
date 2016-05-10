#include <iostream>

using namespace std;

struct ListNode {
  int val;
  ListNode *next;
  ListNode(int x) : val(x) {}
};

ListNode *detectCycle(ListNode *head);
int main() {
  ListNode *head = new ListNode(1);
  head->next = new ListNode(2);
  head->next->next = head;
  cout << detectCycle(head)->val << endl;
  return 0;
}

ListNode *detectCycle(ListNode *head) {
    if (head == 0 || 0 == head->next)
      return 0;
    if (head == head->next)
      return head;
    ListNode *fast = head, *slow = head;
    int k = 0;
    bool flag = true;
    while (fast != slow || flag) {
      flag = false;
      if (fast == 0 || fast->next == 0)
	return 0;
      k++;
      fast = fast->next->next;
      slow = slow->next;
    }

    while (k != 0) {
      k--;
      slow = slow->next;
    }
    return slow;
  }  return slow;
}
