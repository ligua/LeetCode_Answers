//Calculate the sum of two integers a and b, but you are not allowed to use the operator + and - .
//
//Example:
//Given a = 1 and b = 2, return 3.
//
//Credits :

int getSum(int a, int b)
{
	if (a == 0)
		return b;
	else if (b == 0)
		return a;
	return getSum(a^b, (a&b) << 1);
}