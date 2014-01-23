class Solution {
public:
  bool isvalid(vector<vector<char> > &board, int i, int j) {
    // check row
    for (int k = 0; k < 9; k++) {
      if (k == i) continue;
      if (board[k][j] == board[i][j])
	return false;
    }
    // check col
    for (int k = 0; k < 9; k++) {
      if (k == j) continue;
      if (board[i][k] == board[i][j])
	return false;
    }
    // check square
    int ii = i/3;
    int jj = j/3;
    for (int k = ii*3; k < ii*3+3; k++) {
      for (int kk = jj*3; kk < jj*3+3; kk++) {
	if (k == i && kk == j) continue;
	if (board[k][kk] == board[i][j])
	  return false;
      }
    }
    return true;
  }
  bool isValidSudoku(vector<vector<char> > &board) {
    for (int i = 0; i < 9; i++) {
      for (int j = 0; j < 9; j++) {
	if (board[i][j] != '.') {
	  if (!isvalid(board, i, j))
	    return false;
	}
      }
    }
    return true;
  }
};
