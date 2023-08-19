#include <iostream>;
#include <vector>

using namespace std;

int main() {
	int n, k;
	cin >> n >> k;

	int lish = n % 4;
	int konov = n / 4;
	int pos = k - (konov % 4);
	if (pos < 1) {
		pos += 4;
	}
	int res = konov;
	if (pos <= lish) {
		res += 1;
	}
	cout << res;
}