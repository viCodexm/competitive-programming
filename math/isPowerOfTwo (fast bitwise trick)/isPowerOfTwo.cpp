bool isPowerOfTwo(int num) const
{
    if( (num & (num - 1)) || num < 2) {
		    return false;
	  }
	  return true; 
}
