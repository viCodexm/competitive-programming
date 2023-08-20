#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;


int main() {
	long long int n, lists;
	cin >> n >> lists;
	vector<long long int> a;
	for (long long int i = 0; i < n; ++i) {
		long long l, r, price;
		cin >> l >> r >> price;
		if (lists > r) continue;
		long long int totalprice = 0;
		//надо добрать
		if (lists < l) {
			totalprice = l * price;
		}
		else {
			totalprice = lists * price;
		}
		a.push_back(totalprice);
	}
	if (a.size() == 0) {
		cout << "-1";
		return 0;
	}
	sort(a.begin(), a.end());
	cout << a[0];
}