#include <iostream>
#include <vector>

using namespace std;

void rotate(vector<vector<int> > &matrix);
void swap(int& a, int& b);
int main() {
  // insert your code here
  vector<vector<int> > test;
  vector<int> temp;
  temp.push_back(1);
  temp.push_back(2);
  temp.push_back(3);
  test.push_back(temp);
  temp.clear();
  temp.push_back(4);
  temp.push_back(5);
  temp.push_back(6);
  test.push_back(temp);
  temp.clear();
  temp.push_back(7);
  temp.push_back(8);
  temp.push_back(9);
  test.push_back(temp);
  rotate(test);

  for (int i = 0; i < test.size(); i++) {
    for (int j = 0; j < test.size(); j++)
      cout << test[i][j] << ' ';
    cout << endl;
  }
  
  return 0;
}

void swap(int& a, int& b) {
  if (a == b)
    return;
  cout << "swap: " << a << " & " << b << endl;
  a = a + b;
  b = a - b;
  a = a - b;
}

void rotate(vector<vector<int> > &matrix) {
  if (matrix.size() <= 1) {
    return;
  }  
  int s = matrix.size()-1;
  int n = s/2+1;
  int m = n;
  if (s%2 == 0)
    m--;
  cout << "s&n: " << s << ' ' << n << endl;
  for (int i = 0; i < m; i++) {
    for (int j = 0; j < n; j++) {
      swap(matrix[i][j], matrix[j][s-i]);
      swap(matrix[i][j], matrix[s-i][s-j]);
      swap(matrix[i][j], matrix[s-j][i]);
    }
  }
  return;
}
