#include <iostream>;
#define ll long long
using namespace std;
int main() {
	ll n;
	cin >> n;
	ll sum = 0;
	for (int i = 0; i < n; ++i) {
		ll x, y;
		cin >> x >> y;
		sum += x * y;
	}
	cout << sum;
}