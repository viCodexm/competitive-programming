int_fast64_t BinaryPow(int_fast64_t x, int_fast64_t k) {
	int_fast64_t res = 1;
	while (k > 0) {
		if (k % 2 == 1)
			res *= x;
		x *= x;
		k /= 2;
	}
	return res;
}