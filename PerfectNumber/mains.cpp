#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int numSquares(int n) {
    vector<int> perfect;
    for (int i = 0; i <= n; i++) {
	perfect.push_back(i);
    }
        
    for (int i = 1; i <= n; i++) {
	for (int j = 1; j <= sqrt(i); j++) {
	    perfect[i] = min(perfect[i-j*j]+1, perfect[i]); 
	}
	cout << perfect[i] << ' ';
    }
    cout << endl;
    return perfect[n];
}

int main() {
    cout << numSquares(7) << endl;
    return 0;
}
