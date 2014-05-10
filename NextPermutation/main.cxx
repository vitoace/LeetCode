#include <iostream>
#include <vector>

using namespace std;

void nextPermutation(vector<int> &num);
int main() {
  vector<int> test;
  //for (int i = 100; i > 0; i--) {
  //  test.push_back(i);
  //}
  test.push_back(1);
  test.push_back(2);
  nextPermutation(test);
  for (int i = 0; i < test.size(); i++)
    cout << test[i] << ' ';
  cout << endl;
  return 0;
}

void nextPermutation(vector<int> &num) {
  if (num.size() == 1)
    return;
  int g = num[num.size()-1];
  int i, pos = num.size();
  for (int i = num.size()-2; i >= 0; i--) {
    if (g <= num[i]) {
      g = num[i];
    }
    else {
      pos = i;
      break;
    }
  }
        
  if (pos == num.size()) {
    std::reverse(num.begin(), num.end());
  }
        
  else {
    for (int i = num.size()-1; i >= 0; i--) {
      if (num[i] > num[pos]) {
	std::swap(num[i], num[pos]);
	break;
      }
    }
    std::reverse(num.begin()+pos+1, num.end());
  }
}
