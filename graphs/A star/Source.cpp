#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <set>
#include <queue>

using namespace std;
#define fo(i, n) for (i = 0; i < n; ++i)
#define wall '#'
pair<int, int> findPoint(char target, vector<string>& grid) {
	int i = 0, j = 0;
	fo(i, grid.size())
		fo(j, grid[0].size())
		if (grid[i][j] == target)
			return pair{ i, j };
};
struct valpar { int value = 0; pair<int, int> parent; };
vector<vector<valpar>> make_digital(vector<string>& grid) {
	vector<vector<valpar>> digital(grid.size(), vector<valpar>(grid[0].size()));
	int i = 0, j = 0;
	fo(i, grid.size())
		fo(j, grid[0].size())
		if (grid[i][j] == wall)
			digital[i][j].value = INT_MAX;
		else digital[i][j].value = 0;
	return digital;
}
struct wPos { int weight; int i; int j; };
bool operator> (const wPos& Left, const wPos& Right) {
	return Left.weight < Right.weight;
};
bool operator< (const wPos& Left, const wPos& Right) {
	return Left.weight > Right.weight;
};

int main() {
	vector<string> grid = {
		{"           "},
		{" #B        "},
		{"########   "},
		{"       ### "},
		{"       A   "},
		{"           "},
	};
	for (auto& line : grid) {
		for (auto& e : line)
			cout << e;
		cout << endl;
	}
	pair<int, int> Bloc = findPoint('B', grid);
	pair<int, int> Aloc = findPoint('A', grid);

	vector<vector<valpar>> digital = make_digital(grid);
	vector<vector<bool>> visited(grid.size(), vector<bool>(grid[0].size()));
	
	auto caclNeighbours = [](pair<int, int> current, pair<int, int>& target, pair<int, int>& from, vector<vector<valpar>>& digital, vector<vector<bool>>& visited, priority_queue<wPos>& pq) {
		#define sqr(x)	pow(x, 2)
		for (int i = -1; i < 2; ++i)
			for (int j = -1; j < 2; ++j) {
				if (i == j && i == 0) continue;
				int a = current.first + i; int b = current.second + j;
				if (0 <= a && a < digital.size()
					&& 0 <= b && b < digital[0].size()) {
					float G_cost = sqrt(sqr(a - from.first) + sqr(b - from.second)) * 10;
					float H_cost = sqrt(sqr(a - target.first) + sqr(b - target.second)) * 10;
					int F_cost = G_cost + H_cost;
					
					if (not visited[a][b] && digital[a][b].value != INT_MAX) {
						if (digital[a][b].value == 0 || F_cost < digital[a][b].value) {
							digital[a][b].value = F_cost;
							digital[a][b].parent.first = current.first; digital[a][b].parent.second = current.second;
						}
						pq.push(wPos{ digital[a][b].value,a,b });
					}
				}
			}
	};
	priority_queue<wPos> pq;
	pq.push(wPos{ 0, Aloc.first, Aloc.second });
	while (!pq.empty()) {
		wPos current = pq.top();
		visited[current.i][current.j] = true;
		pq.pop();

		if (current.i == Bloc.first && current.j == Bloc.second) {
			cout << "Path found!\n";
			break;
		}
		caclNeighbours(pair{ current.i, current.j }, Bloc, Aloc, digital, visited, pq);

	}
	grid[Bloc.first][Bloc.second] = '*';
	pair<int, int> cur = digital[Bloc.first][Bloc.second].parent;
	grid[cur.first][cur.second] = '*';
	while (cur != Aloc) {
		cur = digital[cur.first][cur.second].parent;
		grid[cur.first][cur.second] = '*';
	}
	cout << "OUTPUT:\n";
	for (auto& line : grid) {
		for (auto& e : line)
			cout << e;
		cout << endl;
	}

	
}