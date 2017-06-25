#include <iostream>
#include <vector>

using namespace std;

double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
  int s1 = nums1.size();
  int s2 = nums2.size();
  if (s1 > s2) {
    vector<int> temp = nums1;
    nums1 = nums2;
    nums2 = temp;
    s1 += s2;
    s2 = s1 - s2;
    s1 = s1 - s2;
  }
  int median = (s1 + s2 + 1) / 2;
  int begin = 0, end = s1;
  while(begin <= end) {
    int i = (begin + end) / 2;
    int j = median -i;
    if ((i < s1) && (nums2[j-1] > nums1[i]))
      begin = i + 1;
    else if ((i > 0) && (nums1[i-1] > nums2[j]))
      end = i - 1;
    else {
      int max_of_left, min_of_right;
      if (i == 0) max_of_left = nums2[j-1];
      else if (j == 0) max_of_left = nums1[i-1];
      else max_of_left = max(nums1[i-1], nums2[j-1]);
                
      if ((s1 + s2) % 2 == 1)
	return max_of_left;
      if (i == s1) min_of_right = nums2[j];
      else if (j == s2) min_of_right = nums1[i];
      else min_of_right = min(nums1[i], nums2[j]);
      return (max_of_left + min_of_right) / 2.0;
    }
  }
}


int main() {
  vector<int> v;
}
