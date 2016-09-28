#include <iostream>
#include <stack>

using namespace std;

int lastRemaining(int n);
int main() {
    cout << lastRemaining(9) << endl;
    return 0;
}

int lastRemaining(int n) {
    int res = 1;
    int fromBeginning = true;
    stack<bool> odd;
    while (n > 1) {
	odd.push(fromBeginning || n % 2 == 1);
	n /= 2;
	fromBeginning = !fromBeginning;
    }
    cout << odd.size() << endl;
    while(!odd.empty()) {
	cout << odd.top() << endl;
	if (odd.top()) res *= 2;
	else res = res*2-1;
	odd.pop();
    }
    return res;
}
