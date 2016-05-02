#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
  int hIndex(vector<int>& citations) {
    int hindex = 0;
    sort(citations.begin(), citations.end());
    int l = citations.size();
    for (int i = 0; i < l; i++) {
      if (citations[i] >= l-i)
	hindex = max(hindex, l - i);
    }
    return hindex;
  }

private:
  void printVector(const vector<int>& vec) {
    for (int i = 0; i < vec.size(); i++) {
      cout << vec[i] << ' ';
    }
    cout << endl;
  }

};


int main() {
  vector<int> citations;
  citations.push_back(3);
  citations.push_back(0);
  citations.push_back(6);
  citations.push_back(1);
  citations.push_back(5);
  Solution s;
  cout << "H-Index: " << s.hIndex(citations) << endl;
  return 0;
}
