#include <iostream>

#include "LRUCache.h"

using namespace std;

LRUCache::LRUCache(int capacity) : cap(capacity) {
  head = 0;
  tail = 0;
}

int LRUCache::get(int key) {
  if (map.find(key) == map.end()) {
    return -1;
  }
  else { // return value and update map
      moveToHead(map[key]);
      return map[key]->val;
  }
}

void LRUCache::set(int key, int val) {
  if (map.find(key) == map.end()) { // no found
    if (map.size() == cap) { // full
      pop();
      insert(key, val);
    }
    else { // not full
      insert(key, val);
    }
  }
  else { // found
    moveToHead(map[key]);
    map[key]->val = val;
  }
}

void LRUCache::moveToHead(LinkList* cur) {
  if (map.size() <= 1 || cur == tail)
    return;
  if (head == cur)
    head = head->next;
  LinkList* prev = cur->prev;
  LinkList* next = cur->next;
  if (prev != 0)
    prev->next = next;
  if (next != 0)
    next->prev = prev;
  cur->next = 0;
  cur->prev = tail;
  tail->next = cur;
  tail = cur;
}

void LRUCache::pop() {
  int key = head->key;
  // update map
  map.erase(key);
  // update LinkList
  LinkList* cur = head;
  head = head->next;
  delete cur;
  if (head != 0)
    head->prev = 0;
}

void LRUCache::insert(int key, int val) {
  LinkList* temp = new LinkList(key, val);
  if (head == NULL || tail == NULL) {
    // update LinkList
    head = temp;
    tail = temp;

    // update map
    map[key] = temp;
    return;
  }
    
  // update map
  map[key] = temp;
  // update LinkList
  tail->next = temp;
  temp->prev = tail;
  tail = temp;
}

void LRUCache::print() {
  cout << "===================" << endl;
  cout << "size: " << map.size() << endl;
  LinkList* cur = head;
  while(cur != 0) {
    cout << cur->key << ' ' << cur->val << endl;
    cur = cur->next;
  }
}

