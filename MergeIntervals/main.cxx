#include <iostream>
#include <vector>

using namespace std;

struct Interval {
  int start;
  int end;
  Interval(int s, int e) : start(s), end(e) {}
  Interval() : start(0), end(0) {}
};

vector<Interval> merge(vector<Interval> &intervals);
int main() {
  vector<Interval> test;
  Interval temp1(1,4);
  Interval temp3(1,4);
  test.push_back(temp1);
  test.push_back(temp3);  
  vector<Interval> res = merge(test);
  
  for (int i = 0; i < res.size(); i++)
    cout << '[' << res[i].start << ", " << res[i].end << "] ";
  cout << endl;

  return 0;
}
vector<Interval> Merge(vector<Interval> int1, vector<Interval> int2) {
  int i = 0, j = 0;
  vector<Interval> res;
  while(i < int1.size() && j < int2.size()) {
    if (int1[i].start <= int2[j].start) {
      res.push_back(int1[i]);
      i++;
    }
    else {
      res.push_back(int2[j]);
      j++;
    }
  }
        
  while(i < int1.size()) {
    res.push_back(int1[i]);
    i++;
  }
  while(j < int2.size()) {
    res.push_back(int2[j]);
    j++;
  }
  return res;
}
    
vector<Interval> mergeSort(vector<Interval> intervals) {
  if (intervals.size() <= 1)
    return intervals;
  int mid = intervals.size()/2;
  vector<Interval> left;
  for (int i = 0; i < mid; i++)
    left.push_back(intervals[i]);

  vector<Interval> right;
  for (int i = mid; i < intervals.size(); i++)
    right.push_back(intervals[i]);

  return Merge(mergeSort(left), mergeSort(right));
}
    
bool myFun(const Interval& i1, const Interval& i2) {
  return (i1.start <= i2.start);
}

vector<Interval> merge(vector<Interval> &intervals) {
  if (intervals.size() <= 1)
    return intervals;
  //sort Intervals based on start
  //intervals = mergeSort(intervals);
  std::sort(intervals.begin(), intervals.end(), myFun);
  vector<Interval> res;

  Interval a = intervals[0];
  for (int i = 1; i < intervals.size(); i++) {
    if (a.end >= intervals[i].start) {
      a.start = min(a.start, intervals[i].start);
      a.end = max(a.end, intervals[i].end);
    }
    else {
      res.push_back(a);
      a = intervals[i];
    }
  }
  res.push_back(a);
  return res;
}
