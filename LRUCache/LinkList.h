class LinkList {
 public:
  int key, val;
  LinkList* next;
  LinkList* prev;
  LinkList(int key, int val) : key(key), val(val) {
    next = 0;
    prev = 0;
  }
};
