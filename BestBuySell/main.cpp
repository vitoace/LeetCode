#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int maxProfit(vector<int> &prices);
int main() {
  // insert your code here
  vector<int> prices;
  prices.push_back(1);
  prices.push_back(2);

  cout << maxProfit(prices) << endl;
  return 0;
}

int maxProfit(vector<int>& prices) {
  if (prices.size() <= 1)
    return 0;

  // initialize
  int len = prices.size();
  vector<int> historyProfit;
  vector<int> futureProfit;
  for (int i = 0; i < len; i++) {
    historyProfit.push_back(0);
    futureProfit.push_back(0);
  }
  int res = 0;
  // forward
  int valley = prices[0];
  for (int i = 0; i < len; ++i) {
    valley = min(valley, prices[i]);
    if (i > 0)
      historyProfit[i] = max(historyProfit[i-1], prices[i] - valley);
  }
  // backward
  int peak = prices[len-1];
  for (int i = len - 1; i >= 0; i--) {
    peak = max(peak, prices[i]);
    if (i < len - 1)
      futureProfit[i] = max(futureProfit[i+1], peak - prices[i]);
    res = max(res, futureProfit[i]+historyProfit[i]);
  }
  return res;
}
