#include <iostream>
#include <unordered_map>

#include "LRUCache.h"

using namespace std;

int main() {
  LRUCache cache(3);
  cache.set(1,1);
  cache.print();  
  cache.set(2,2);
  cache.print();  
  cache.set(3,3);
  cache.print();  
  cache.set(4,4);
  cache.print();  
  cout << cache.get(4) << endl;
  cache.print();
  cout << cache.get(3) << endl;
  cache.print();
  cout << cache.get(2) << endl;
  cache.print();
  cout << cache.get(1) << endl;
  cache.print();
  cache.set(5,5);
  cout << cache.get(1) << endl;
  cout << cache.get(2) << endl;
  cout << cache.get(3) << endl;
  cout << cache.get(4) << endl;
  cout << cache.get(5) << endl;
  cache.print();
  return 0;
}
