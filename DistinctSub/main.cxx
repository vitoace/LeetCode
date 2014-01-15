#include <iostream>

using namespace std;

int numDistinct(string S, string T);
int main() {
  string S("rabbbit");
  string T("rabit");
  cout << numDistinct(S, T) << endl;
  return 0;
}

int numDistinct(string S, string T) {
  if (S.size() < T.size())
    return 0;
  int sizeS = S.size();
  int sizeT = T.size();
  int res[sizeT+1][sizeS+1];
  for (int i = 0; i <= sizeT; i++)
    res[i][0] = 0;
  for (int i = 0; i <= sizeS; i++)
    res[0][i] = 1;
        
  for(int i = 1; i <= sizeT; i++)
    for (int j = 1; j <= sizeS; j++) {
      res[i][j] = res[i][j-1];
      if (S[j-1] == T[i-1])
	res[i][j] += res[i-1][j-1];
    }
  for (int i = 0; i <= sizeT; i++) {
    for (int j = 0; j <= sizeS; j++)
      cout << res[i][j] << ' ';
    cout << endl;
  }
  return res[sizeT][sizeS];
}
