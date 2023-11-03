
#include <bits/stdc++.h>

using namespace std;

int Solution() {
	int n; cin >> n;
  // ... input ...
	int ans = 0; // use 'tuple' in case of diverse output
	// ... solution ...

  // ... debug ...
	#ifndef ONLINE_JUDGE
		int expected; cin >> expected;
		bool passed = (ans == expected);
		printf("Got: %d Expected: %d Test %s", ans, expected, passed ? "Passed V\n" : "Failed X\n");
		return passed;
	#else
    // ... answer ...
		cout << ans << "\n";
		return 0;
	#endif
}

int main() {
	#ifndef ONLINE_JUDGE
        #define _CRT_SECURE_NO_WARNINGS
        #include <cstdio>
        freopen("input.txt", "r", stdin);
		
		const int tests = 4;
		bool Accepted = true;
		for (int i = 0; i < tests; ++i)
			Accepted &= Solution();

		(Accepted) ? cout << "\nAccepted!" : cout << "\nFailed.";
	#else
		Solution();
    #endif
	
	return 0;
}
