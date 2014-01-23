#include <iostream>

using namespace std;

int removeDuplicates(int A[], int n);
int main() {
  // insert your code here
  int A[] = {1, 1, 2};
  cout << removeDuplicates(A, 3) << endl;
  return 0;
}

int removeDuplicates(int A[], int n) {
  if (n <= 1)
    return n;
  int len = 1;
  for (int i = 1; i < n; i++) {
    if (A[i] != A[i-1]) {
      A[len] = A[i];
      len++;
    }
  }
  return len;
}
