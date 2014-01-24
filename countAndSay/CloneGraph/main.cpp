#include <iostream>
#include <vector>
#include <queue>
#include <map>

using namespace std;

int main() {
  // insert your code here

  return 0;
}

struct UndirectedGraphNode {
  int label;
  vector<UndirectedGraphNode *> neighbors;
  UndirectedGraphNode(int x) : label(x) {};
};

UndirectedGraphNode *cloneGraph(UndirectedGraphNode *node) {
  if (node == 0)
    return 0;
  map<UndirectedGraphNode*, UndirectedGraphNode*> myMap;
  queue<UndirectedGraphNode*> q;
  q.push(node);
  UndirectedGraphNode* n = new UndirectedGraphNode(node->label);
  myMap[node] = n;
  while(!q.empty()) {
    UndirectedGraphNode* cur = q.front();
    q.pop();

    for (int i = 0; i < cur->neighbors.size(); i++) {
      if (myMap.find(cur->neighbors[i]) == myMap.end()) {
	UndirectedGraphNode* neighbor = new UndirectedGraphNode(cur->neighbors[i]->label);
	myMap[cur]->neighbors.push_back(neighbor);
	myMap[cur->neighbors[i]] = neighbor;
	q.push(cur->neighbors[i]);
      }
      else {
	myMap[cur]->neighbors.push_back(myMap[cur->neighbors[i]]);
      }
    }
  }
  return myMap[node];
}
