#include <unordered_map>
#include "LinkList.h"

class LRUCache {
 public:
  LRUCache(int capacity);
  int get(int key);
  void set(int key, int val);
  void print();

 private:
  int cap;
  std::unordered_map<int, LinkList*> map;
  LinkList* head;
  LinkList* tail;
  
  void moveToHead(LinkList*);
  void pop();
  void insert(int k, int v);
};
