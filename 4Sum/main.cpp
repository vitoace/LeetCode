#include <iostream>
#include <vector>
#include <unordered_map>
#include <set>

using namespace std;

vector<vector<int> > fourSum_n3(vector<int> &num, int target);
vector<vector<int> > fourSum(vector<int> &num, int target);
int main() {
  vector<int> num;
  num.push_back(0);
  num.push_back(0);
  num.push_back(0);
  num.push_back(0);
  vector<vector<int> > res = fourSum_n3(num, 0);
  for (int i = 0; i < res.size(); i++) {
    for (int j = 0; j < res[i].size(); j++) {
      cout << res[i][j] << ' ';
    }
    cout << endl;
  }
  return 0;
}

vector<vector<int> > fourSum(vector<int> &num, int target) {
  std::sort(num.begin(), num.end());
  vector<vector<int> > res;
  if (num.size() < 4)
    return res;
        
  for (int i = 0; i < num.size()-3; i++) {
    vector<int> temp(4, 0);
    int residual = target - num[i];
    if (residual < 0)
      break;
    temp[0] = num[i];
    for (int j = i+1; j < num.size()-2; j++) {
      residual -= num[j];
      if (residual < 0)
	break;
      temp[1] = num[j];
      for (int k = j+1; k < num.size()-1; k++) {
	residual -= num[k];
	if (residual < 0)
	  break;
	temp[2] = num[k];
	for (int ii = k+1; ii < num.size(); ii++) {
	  residual -= num[ii];
	  if (residual == 0) {
	    temp[3] = num[ii];
	    res.push_back(temp);
	    break;
	  }
	  residual += num[ii];
	}
	residual += num[k];
      }   
      residual += num[j];
    }
    residual += num[i];
  }
  return res;
}

struct myPair {
  int first;
  int second;
  myPair(int a, int b):first(a), second(b) {
  }
  int sum() {
    return first+second;
  }
};

vector<vector<int> > fourSum_n3(vector<int> &num, int target) {
  std::sort(num.begin(), num.end());
  set<string> isExist;
  vector<vector<int> > res;
  if (num.size() < 4)
    return res;

  vector<int> temp;
  for (int i = 0; i < num.size()-3; i++) {
    temp.push_back(num[i]);
    for (int j = i+1; j < num.size()-2; j++) {
      temp.push_back(num[j]);
      int b = j+1;
      int e = num.size()-1;
      while (b < e) {
	int residual = target - temp[0] - temp[1] - num[b] - num[e];
	if (residual == 0) {
	  string t = "";
	  t += temp[0];
	  t += ",";
	  t += temp[1];
	  t += ",";
	  t += num[b];
	  t += ",";
	  t += num[e];
	  set<string>::iterator it = isExist.find(t);
	  if (it == isExist.end()) {
	    isExist.insert(t);
	    temp.push_back(num[b]);
	    temp.push_back(num[e]);
	    res.push_back(temp);
	    temp.pop_back();
	    temp.pop_back();
	  }
	  b++;
	  e--;
	}
	else if (residual < 0) {
	  e--;
	}
	else {
	  b++;
	}
      }
      temp.pop_back();
    }
    temp.pop_back();
  }
  return res;
}
