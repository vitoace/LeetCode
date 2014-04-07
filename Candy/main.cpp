#include <iostream>
#include <vector>

using namespace std;

int candy(vector<int> &ratings);
int main() {
  vector<int> ratings;
  ratings.push_back(1);
  ratings.push_back(2);
  ratings.push_back(3);
  ratings.push_back(4);
  ratings.push_back(5);
  ratings.push_back(6);
  ratings.push_back(7);
  ratings.push_back(6);
  ratings.push_back(5);
  ratings.push_back(4);
  ratings.push_back(3);
  cout << candy(ratings) << endl;
  return 0;
}

int candy(vector<int> &ratings) {
  if (ratings.size() == 0)
    return 0;
  int sum = 0;
  vector<int> candies;
  candies.push_back(1);
  for (int i = 1; i < ratings.size(); i++)
    if (ratings[i] > ratings[i-1])
      candies.push_back(candies[i-1]+1);
    else
      candies.push_back(1);
  
  for (int i = ratings.size() - 2; i >= 0; i--) {
    if (ratings[i] > ratings[i+1] && candies[i] <= candies[i+1]) {
      candies[i] = candies[i+1]+1;
    }
  }
        
  for (int i = 0; i < candies.size(); i++) {
    cout << ratings[i] << ' ';
    cout << candies[i] << endl;
    sum += candies[i];
  }
  return sum;
}
