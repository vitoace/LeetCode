#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int numIslands(vector<vector<char> >& grid);
int main() {
    vector<char> tmp;
    tmp.push_back('1');
    tmp.push_back('1');
    tmp.push_back('1');
    tmp.push_back('1');
    tmp.push_back('0');
    vector<vector<char> > grid;
    grid.push_back(tmp);
    cout << numIslands(grid) << endl;
    return 0;
}

int numIslands(vector<vector<char> >& grid) {
    if (grid.size() == 0 || grid[0].size() == 0) return 0;

    vector<vector<bool> > visited;
    for (int i = 0; i < grid.size(); i++) {
	vector<bool> tmp;
	for (int j = 0; j < grid[0].size(); j++) {
	    tmp.push_back(false);
	}
	visited.push_back(tmp);
    }
        
    int count = 0;
    for (int i = 0; i < grid.size(); ++i) {
	for (int j = 0; j < grid[i].size(); ++j) {
	    if (!visited[i][j] && grid[i][j] == '1') {
		visited[i][j] = true;
		queue<pair<int, int> > q;
		q.push(make_pair(i, j));
		while(!q.empty()) {
		    pair<int, int> p = q.front();
		    q.pop();
		    int m = p.first, n = p.second;
		    cout << m << ' ' << n << endl;
		    if (m > 0 && grid[m-1][n] == '1' && !visited[m-1][n]) {
			q.push(make_pair(m-1, n));
			visited[m-1][n] = true;
		    }
		    if (n > 0 && grid[m][n-1] == '1' && !visited[m][n-1]) {
			q.push(make_pair(m, n-1));
			visited[m][n-1] = true;
		    }
		    if (m < grid.size()-1 && grid[m+1][n] == '1' && !visited[m+1][n]) {
			q.push(make_pair(m+1, n));
			visited[m+1][n] = true;
		    }
		    if (n < grid[i].size()-1 && grid[m][n+1] == '1' && !visited[m][n+1]) {
			q.push(make_pair(m, n+1));
			visited[m][n+1] = true;
		    }
		}
		count++;
	    }
	}
    }
    return count;
}
