#include <iostream>
#include <vector>

using namespace std;
// This code was used to solve this problem: https://acm.bsuir.by/solve/contests/4/problems/I
//	(0 1)^N
//	(1 1)

//	(0 1) (0 1)
//	(1 1) (1 1)

#define vec2 vector<vector<long long>>
#define modulo 1'000'000'007

vec2 mul(vec2 p, vec2 b);

vec2 operator* (const vec2& left, const vec2& right) {
	return mul(left, right);
}

long long BinaryPow(vec2& x, unsigned long long k) {
	vec2 res = x;
	while (k > 0) {
		if (k & 1)
			res = res * x;
		x = x * x;
		k /= 2;
	}
	return (res[0][0] % modulo);
}

vec2 mul(vec2 p, vec2 b) {
	vec2 temp = b;
	temp[0][0] = ((p[0][0] * b[0][0]) % modulo + (p[0][1] * b[1][0]) % modulo) % modulo;
	temp[0][1] = ((p[0][0] * b[0][1]) % modulo + (p[0][1] * b[1][1]) % modulo) % modulo;
	temp[1][0] = ((p[1][0] * b[0][0]) % modulo + (p[1][1] * b[0][1]) % modulo) % modulo;
	temp[1][1] = ((p[1][0] * b[0][1]) % modulo + (p[1][1] * b[1][1]) % modulo) % modulo;
	b = temp;
	return b;
}

int main() {
	vec2 p = { {0, 1},
			   {1, 1} };
	unsigned long long n; cin >> n;
	cout << BinaryPow(p, n);
}
