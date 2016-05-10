#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>

using namespace std;

int LargestRectangleInHistogram(vector<int> height);
int main() {
  vector<int> height;
  height.push_back(2);
  height.push_back(1);
  height.push_back(5);
  height.push_back(6);
  height.push_back(2);
  height.push_back(3);

  cout << LargestRectangleInHistogram(height) << endl;
  return 0;
}

int LargestRectangleInHistogram(vector<int> height) {
  height.push_back(0);
  int size = height.size();
  int maxArea = 0;
  stack<int> st;
  for (int i = 0; i < size; i++) {
    cout << "i = " << i << endl;
    if (st.empty() || height[st.top()] < height[i]) {
      cout << "push index " << i << " into stack." << endl;
      st.push(i);
    }
    else {
      int tmp = st.top();
      cout << "st.top() = " << tmp << endl;
      st.pop();
      cout << "height[st.top()] = " << height[tmp] << " " << " width = " << (st.empty() ? i : i - st.top() - 1) << endl;
      maxArea = max(maxArea, height[tmp]*(st.empty() ? i : i - st.top() - 1));
      i--;
    }
    cout << "Max area: " << maxArea << endl;
    cout << "=====================================" << endl;
  }
  return maxArea;
}
