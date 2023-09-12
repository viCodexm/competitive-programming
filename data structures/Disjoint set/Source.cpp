
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


// `1 <= n` indexation
class DisjointSet {
public:
	vector<int> parent;

	DisjointSet(int n) {
		parent.resize(n + 1);
		for (int i = 1; i <= n; ++i)
			parent[i] = i;
	}
	int getRep(int i) {
		if (parent[i] != i)
			parent[i] = getRep(parent[i]);
		return parent[i];
	}
	void join(int u, int v) {
		int RepU = getRep(u);
		int RepV = getRep(v);
		if (RepU == RepV) return;
		if (rand() % 2)
			parent[RepU] = RepV;
		else parent[RepV] = RepU;
	}
};

int main() {
	ios_base::sync_with_stdio(NULL);
	cin.tie(NULL);
	
	DisjointSet ds(8);
	
	/* Example of finding `Minimal Spanning Tree` using Kruskall's algorithm*/
	
	struct ftw {
		int from, to, weight;
	};
	vector<ftw> input =
	{
		{1, 2, 5},
		{1, 3, 15},
		{1, 7, 1},
		{2, 1, 5},
		{2, 4, 3},
		{3, 1, 15},
		{3, 7, 10},
		{4, 2, 3},
		{4, 5, 4},
		{4, 6, 9},
		{5, 4, 4},
		{5, 8, 4},
		{6, 4, 9},
		{6, 8, 11},
		{7, 1, 1},
		{7, 3, 10},
		{7, 8, 3},
		{8, 5, 4},
		{8, 6, 11},
		{8, 7, 3}
	};
	
	sort(input.begin(), input.end(), [](const ftw& left, const ftw& right) {
		return left.weight < right.weight;
	});
	
	int totalWeight = 0;
	for (ftw& edge : input) {
		int from = edge.from;
		int to = edge.to;
		int weight = edge.weight;
		if (ds.getRep(from) != ds.getRep(to)) {
			ds.join(from, to);
			totalWeight += weight;
		}
	}
	cout << totalWeight << "\n";
	cout << "Expected weight is 34\n";
	return 0;
}
