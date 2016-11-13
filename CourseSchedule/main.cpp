#include <iostream>
#include <set>
#include <vector>
#include <queue>

using namespace std;

typedef vector<set<int> > Graph;

Graph buildGraph(int numCourses, vector<pair<int, int> > &pre);
bool canFinish(int numCourses, const vector<pair<int, int> >& prerequisites);
int main() {
  vector<pair<int, int> > pre;
  pre.push_back(make_pair(0,1));
  pre.push_back(make_pair(0,2));
  pre.push_back(make_pair(1,2));
  cout << canFinish(3, pre) << endl;
  return 0;
}

Graph buildGraph(int numCourses, const vector<pair<int, int> > &pre) {
  Graph g(numCourses, set<int>());
  for (vector<pair<int, int> >::const_iterator it = pre.begin(); it != pre.end(); it++) {
    g[it->first].insert(it->second);
  }
  return g;
}

vector<int> computeIndegree(int numCourses, const Graph &g) {
  vector<int> indegree(numCourses);
  for (Graph::const_iterator cit = g.begin(); cit != g.end(); cit++) {
    const set<int> &s = *cit;
    for (set<int>::const_iterator ccit = s.begin(); ccit != s.end(); ccit++) {
      indegree[*ccit]++;
    }
  }
  return indegree;
}

bool canFinish(int numCourses, const vector<pair<int, int> >& prerequisites) {
  if (numCourses <= 0) return true;
  Graph g = buildGraph(numCourses, prerequisites);
  vector<int> indegree = computeIndegree(numCourses, g);
  for (int i = 0; i < numCourses; i++) {
    int j = 0;
    for (; j < numCourses; j++) {
      if (indegree[j] == 0) break;
    }
    if (j == numCourses) return false;
    indegree[j]=-1;
    for (set<int>::const_iterator cit = g[j].begin(); cit != g[j].end(); cit++) {
      indegree[*cit]--;
    }
  }
  return true;
}
