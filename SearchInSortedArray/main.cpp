#include <iostream>

using namespace std;

int search(int A[], int n, int target);
int main() {
  // insert your code here
  int A[] = {5, 1, 3};
  int target = 1;
  cout << search(A, 3, target) << endl;
  return 0;

}

int binarySearch(int A[], int begin, int end, int target) {
  while (begin < end) {
    int mid = (begin+end)/2;
    if (A[mid] == target)
      return mid;
    else if (A[mid] < target)
      begin = mid + 1;
    else
      end = mid - 1;
  }
  return -1;
}

int search(int A[], int n, int target) {
  if (n == 0)
    return 0; 
  if (n == 1)
    return (A[0] == target) ? 0 : -1;

  if (A[0] > A[n-1]) {
    int begin = 0;
    int end = n-1;
    //find the rotated point
    int rotate = 0;
    while (begin < end-1) {
      int mid = (begin+end)/2;
      if (A[mid] < A[begin]) {
	end = mid;
      }
      else {
	begin = mid;
	rotate = mid;
      }
    }
    cout << rotate << endl;
    if (target >= A[0] && target <= A[rotate])
      return binarySearch(A, 0, rotate, target);
    return binarySearch(A, rotate+1, n-1, target);
  }
  else {
    // regular binary search
    return binarySearch(A, 0, n-1, target);
  }
}
