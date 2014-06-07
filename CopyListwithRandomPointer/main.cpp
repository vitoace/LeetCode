#include <iostream>
#include <map>

using namespace std;

struct RandomListNode {
  RandomListNode *next, *random;
  int label;
  RandomListNode(int val) : label(val), next(0), random(0) {};
};

RandomListNode *copyRandomList(RandomListNode *head);
int main() {
  RandomListNode* head = new RandomListNode(-1);
  RandomListNode* headp = copyRandomList(head);
  while (headp != 0) {
    cout << headp->label << ' ';
    headp = headp->next;
  }
  cout << endl;
  return 0;
}

RandomListNode *copyRandomList(RandomListNode *head) {
  RandomListNode *headp = 0;
  RandomListNode *cur = head;
  RandomListNode *curp = 0;
  if (head == 0)
    return headp;
            
  headp = new RandomListNode(head->label);
  curp = headp;
  cur = head->next;
  map<RandomListNode*, RandomListNode*> myMap;
  myMap[head] = headp;
  while(cur != 0) {
    curp->next = new RandomListNode(cur->label);
    curp = curp->next;
    myMap[cur] = curp;
    cur = cur->next;
  }
        
  cur = head;
  curp = headp;
  while (cur != 0) {
    if (cur->random != 0)
      curp->random = myMap[cur->random];
            
    cur = cur->next;
    curp = curp->next;
  }
  return headp;
}
