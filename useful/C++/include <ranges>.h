#include <ranges>

vector<int> a = { 1, 2, 3, 4, 5, 6 };
for (int& e : views::reverse(a))
	cout << e << " "; // 6 5 4 3 2 1
