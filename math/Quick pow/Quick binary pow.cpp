int BinaryPow(int x, unsigned int k) {
	int res = 1;
	while (k > 0) {
		if (k & 1)
			res *= x;
		x *= x;
		k /= 2;
	}
	return res;
}
