#include <iostream>
using namespace std;

struct ListNode {
    ListNode(int i){
	val = i;
    };
    ListNode *next;
    int val;
};

ListNode* addTwoNumbers(ListNode *l1, ListNode *l2);
void printListNode(ListNode *root);

int main() {
    ListNode *l1 = new ListNode(1);
    l1->next = new ListNode(8);
    printListNode(l1);

    ListNode *l2 = new ListNode(0);
    printListNode(l2);
    ListNode* res = addTwoNumbers(l1, l2);
    printListNode(res);
}

void printListNode(ListNode *root) {
    while (root) {
	cout << root->val << "->";
	root = root->next;
    }
    cout << endl;
}
ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
    if (!l1) return l2;
    if (!l2) return l1;
    ListNode *r = new ListNode((l1->val+l2->val)%10);
    bool carry = (l1->val+l2->val)/10;
    ListNode *temp = r;
    l1 = l1->next;
    l2 = l2->next;
  
    while (l1 != NULL && l2 != NULL) {
	int res = (l1->val+l2->val+carry);
	temp->next = new ListNode(res%10);
	carry = res / 10;
    
	temp = temp->next;
	l1 = l1->next;
	l2 = l2->next;
    }

    while (l1 != NULL) {
	int res = l1->val+carry;
	temp->next = new ListNode(res%10);
	temp = temp->next;
	carry = res/10;
	l1 = l1->next;
    }
        
    while (l2 != NULL) {
	int res = l2->val+carry;
	temp->next = new ListNode(res % 10);
	temp = temp->next;
	carry = res / 10;
	l2 = l2->next;
    }
    if (carry) temp->next = new ListNode(1);
        
    return r;
}
