#include <iostream>
#include <vector>

using namespace std;

vector<string> generateParenthesis(int n);
int main() {
  vector<string> res = generateParenthesis(3);
  for (int i = 0; i < res.size(); i++) {
    cout << res[i] << endl;
  }
  return 0;
}

vector<string> generateParenthesis(int n) {
  vector<string> res;
  vector<int> count;
  for (int i = 0; i < n*2; i++) {
    cout << "===========" << i << "==========" << endl;
    if (res.empty()) {
      res.push_back("(");
      count.push_back(1);
    }
    else {
      int size = res.size();
      vector<string> temp_res;
      vector<int> temp_count;
      for (int j = 0; j < size; j++) {
	if (res[j][res[j].length()-1] == '(') {
	  if (count[j] < n && count[j] < n*2-i) {
	    string temp_s = res[j]+"(";
	    temp_res.push_back(temp_s);
	    temp_count.push_back(count[j]+1);
	  }
	  if (count[j] > 0) {
	    string temp_s = res[j]+")";
	    temp_res.push_back(temp_s);
	    temp_count.push_back(count[j]-1);
	  }
	}
	else { // )
	  if (count[j] < n && count[j] < n*2-i) {
	    string temp_s = res[j]+"(";
	    temp_res.push_back(temp_s);
	    temp_count.push_back(count[j]+1);
	  }
	  if (count[j] > 0) {
	    string temp_s = res[j]+")";
	    temp_res.push_back(temp_s);
	    temp_count.push_back(count[j]-1);
	  }
	}
      }
      res = temp_res;
      count = temp_count;
    }
    for (int j = 0; j < res.size(); j++) {
      cout << res[j] << ' ' << count[j] << endl;
    }
  }   
  return res;
}
