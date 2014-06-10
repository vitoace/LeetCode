#include <iostream>
#include <queue>
#include <vector>

using namespace std;

void solve(vector<vector<char> > &board);
int main() {
  vector<vector<char> > test;
  vector<char> temp;
  temp.push_back('X');
  temp.push_back('X');
  temp.push_back('X');
  test.push_back(temp);
  temp.clear();
  temp.push_back('X');
  temp.push_back('O');
  temp.push_back('X');
  test.push_back(temp);
  temp.clear();
  temp.push_back('X');
  temp.push_back('X');
  temp.push_back('X');
  test.push_back(temp);
  solve(test);
  for (int i = 0; i < test.size(); i++) {
    for (int j = 0; j < test[i].size(); j++) {
      cout << test[i][j];
    }
    cout << endl;
  }
  return 0;
}

struct Pair {
  int first, second;
  Pair(int first, int second) : first(first), second(second) {};
};
    
    
void solve(vector<vector<char> > &board) {
  if (board.size() == 0 || board[0].size() == 0)
    return;
  queue<Pair> q;
  int m = board.size();
  int n = board[0].size();
  for (int i = 0; i < m; i++) {
    if (board[i][0] == 'O') {
      Pair t(i, 0);
      q.push(t);
    }
    if (board[i][n-1] == 'O') {
      Pair t(i, n-1);
      q.push(t);
    }
  }
        
  for (int i = 0; i < n; i++) {
    if (board[0][i] == 'O') {
      Pair t(0, i);
      q.push(t);
    }
    if (board[m-1][i] == 'O') {
      Pair t(m-1, i);
      q.push(t);
    }
  }
        
  while (!q.empty()) {
    Pair p = q.front();
    board[p.first][p.second] = 'Y';
    q.pop();
    // up
    if (p.first-1 >= 0 && board[p.first-1][p.second] == 'O') {
      Pair t(p.first-1, p.second);
      q.push(t);
    }
    // down
    if (p.first+1 < m && board[p.first+1][p.second] == 'O') {
      Pair t(p.first+1, p.second);
      q.push(t);
    }
    // left
    if (p.second-1 >= 0 && board[p.first][p.second-1] == 'O') {
      Pair t(p.first, p.second-1);
      q.push(t);
    }
    // right
    if (p.second+1 < n && board[p.first][p.second+1] == 'O') {
      Pair t(p.first, p.second+1);
      q.push(t);
    }
  }
  for (int i = 0; i < m; i++) {
    for (int j = 0; j < n; j++) {
      if (board[i][j] == 'O')
	board[i][j] = 'X';
      if (board[i][j] == 'Y')
	board[i][j] = 'O';
    }
  }
}
