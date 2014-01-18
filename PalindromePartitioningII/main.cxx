#include <vector>

class Solution {
public:
  int minCut(string s) {
    int len = s.size();
    int minCut[len+1];
    bool palTable[len][len];
        
    for (int i = 0; i <= len; i++)
      minCut[i] = len - i - 1;
            
    for (int i = 0; i < len; i++)
      for (int j = 0; j < len; j++)
	palTable[i][j] = false;
        
    for (int i = len; i >= 0; i--)
      for (int j = i; j < len; j++) {
	if (s[i] == s[j] && (j-i < 2 || palTable[i+1][j-1])) {
	  palTable[i][j] = true;
	  minCut[i] = min(minCut[i], minCut[j+1]+1);
	} 
      }
        
    return minCut[0];
  }
}
