#include <vector>

class Solution {
public:
  int minCut(string s) {
    const int n = s.size();
    int minCutTable[n][n];
    bool minCutPalTable[n][n];
    
    // initialize table
    int i;
    for (i = 0; i < n; ++i) {
      minCutPalTable[i][i] = true;
      minCutTable[i][i] = 0;
    }
    
    for (int l = 2; l <= n; l++) {
      for (i = 0; i<n-l+1; i++) {

	int j = i+l-1;
	
	if ( l == 2)
	  minCutPalTable[i][j] = (s[i] == s[j]);
	else
	  minCutPalTable[i][j] = (s[i] == s[j] && minCutPalTable[i+1][j-1]);
	
	if (minCutPalTable[i][j]) {
	  minCutTable[i][j] = 0;
	}
	else {
	  minCutTable[i][j] = n+1;
	  for (int k = i; k <= j-1; ++k) {
	    minCutTable[i][j] = min(minCutTable[i][j], minCutTable[i][k]+minCutTable[k+1][j]+1);
	  }
	}
      }
    }
    return minCutTable[0][n-1];
  }
}
