#include <iostream>

using namespace std;

struct ListNode {
  int val;
  ListNode* next;
  ListNode(int val) : val(val) {}
};

ListNode* sortList(ListNode *head);

int main() {
  return 0;
}

ListNode* merge(ListNode* head1, ListNode* head2);
ListNode* sortList(ListNode *head) {
  if (head == 0 || head->next == 0)
    return head;
        
  ListNode *slow = head, *fast = head;
  while (fast->next != 0 && fast->next->next != 0) {
    slow = slow->next;
    fast = fast->next->next;
  }
  fast = slow->next;
  slow->next = 0;
  slow = sortList(head);
  fast = sortList(fast);
  return merge(slow, fast);
}
    
ListNode* merge(ListNode* head1, ListNode* head2) {
  if (head1 == 0) return head2;
  if (head2 == 0) return head1;
        
  ListNode* res = 0, *cur = 0;
  if (head1->val < head2->val) {
    res = head1;
    head1 = head1->next;
  }
  else {
    res = head2;
    head2 = head2->next;
  }
  cur = res;
  while(head1 != 0 && head2 != 0) {
    if(head1->val < head2->val) {
      cur->next = head1;
      head1 = head1->next;
    }
    else {
      cur->next = head2;
      head2 = head2->next;
    }
    cur = cur->next;
  }
            
  if (head1 != NULL)
    cur->next = head1;
  else if (head2 != NULL)
    cur->next = head2;
  return res;
}
