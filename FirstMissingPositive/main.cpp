#include <iostream>

using namespace std;

int firstMissingPositive(int A[], int n);
int main() {
  int A[4] = {3,4,-1,1};
  cout << firstMissingPositive(A, 4) << endl;
  return 0;
}

int firstMissingPositive(int A[], int n) {
  int i = 0;
  while (i < n) {
    if (A[i]-1 != i && A[i] > 0 && A[i] <= n && A[i] != A[A[i]]) {
      swap(A[i], A[A[i]]);
    }
    else
      i++;
  }

  for (int i = 1; i < n; i++) {
    if (A[i] != i)
      return i+1;
  }
  return n+1;
}
