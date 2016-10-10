#include <iostream>
#include <vector>
#include <string>

using namespace std;

int maxProduct(vector<string>& words);
int main() {
    vector<string> words;
    words.push_back("abcw");
    words.push_back("baz");
    words.push_back("foo");
    words.push_back("bar");
    words.push_back("xtfn");
    words.push_back("abcdef");
    cout << maxProduct(words) << endl;
    return 0;
}

int maxProduct(vector<string>& words) {
    vector<int> bitMap(words.size(), 0);
    for (int i = 0; i < words.size(); i++) {
	for (int j = 0; j < words[i].size(); j++) {
	    bitMap[i] |= (1 << (words[i][j] - 'a'));
	}
    }
    int res = 0;
    for (int i = 0; i < words.size(); i++) {
	int s1 = words[i].size();
	for (int j = i+1; j < words.size(); j++) {
	    int s2 = words[j].size();
	    if (!(bitMap[i] & bitMap[j]))
		res = max(res, s1*s2);
	}
    }
    return res;
}
