#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>

using namespace std;

int LargestRectangleInHistogram(vector<int> height);
int main() {
  vector<int> height;
  height.push_back(3);
  height.push_back(3);
  height.push_back(2);
  height.push_back(2);

  cout << LargestRectangleInHistogram(height) << endl;
  return 0;
}

int LargestRectangleInHistogram(vector<int> height) {
  height.push_back(0);
  int size = height.size();
  int maxArea = 0;
  stack<int> st;
  for (int i = 0; i < size; i++) {
    if (st.empty() || height[st.top()] < height[i]) {
      st.push(i);
    }
    else {
      int tmp = st.top();
      st.pop();
      cout << height[tmp] << " " << i << " " << (st.empty() ? i : i -st.top() - 1) << endl;
      maxArea = max(maxArea, height[tmp]*(st.empty() ? i : i - st.top() - 1));
      cout << i << ": " << maxArea << endl;
      i--;
    }
  }
  return maxArea;
}
