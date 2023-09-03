int BinaryPow(int x, unsigned int k)
{
	int res = 1;
	while (k)
	{
		if (k & 1)
			res *= x;
		x *= x;
		k /= 2;
	}
	return res;
}

double BinPow(double x, int k)
{
	double res = 1.0;
	bool neg = (k < 0);
	k = abs(k);
	while (k)
	{
		if (k & 1)
			res *= x;
		x *= x;
		k /= 2;
	}
	return neg ? (1.0 / res) : res;
}
