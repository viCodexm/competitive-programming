bool isPowerOfTwo(int num)
{
    if((num & (num - 1)) || num < 2)
		return false;
	return true; 
}
