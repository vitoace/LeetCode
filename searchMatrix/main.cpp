#include <iostream>
#include <vector>

using namespace std;

bool searchMatrix(vector<vector<int> >& matrix, int target);
int main() {
  vector<vector<int> > matrix;
  vector<int> temp;
  temp.push_back(1);
  matrix.push_back(temp);  
  if(searchMatrix(matrix,2)) cout << "found" << endl;
  else cout << "not found" << endl;
  return 0;
}

bool searchMatrix(vector<vector<int> >& matrix, int target) {
  int i;
  int begin = 0, end = matrix.size()-1, mid = 0;
  int found = false;
  while(begin <= end) {
    mid = (begin+end)/2;
    if (matrix[mid][0] <= target
	&& matrix[mid][matrix[mid].size()-1] >= target) {
      found = true;
      break;
    }
    if (matrix[mid][0] > target) end = mid-1;
    if (matrix[mid][matrix[mid].size()-1] < target) begin = mid+1;
  }
  if (!found) return found;

  cout << mid << endl;
  vector<int> &vec = matrix[mid];
  begin = 0, end = vec.size()-1;
  while (begin <= end) {
    int mid = (begin+end)/2;
    if (vec[mid] == target) return true;
    else if (vec[mid] > target) end = mid-1;
    else begin = mid+1;
  }
  return false;
}
