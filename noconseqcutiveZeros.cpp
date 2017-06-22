/*This program finds the total possible bit string (either 0 or 1) of length n which don't have two contiguous zeroes in them. */

/*This method takes O(log n) time*/


#include<iostream>
#include<string>
using namespace std;

const unsigned int MAX = 100000000;
const unsigned int M = 1000000007; /*For finding mod(10^9+7) of output*/
/*Array to store previous values*/
unsigned int prevConsqZero[MAX] = { 0 };

/*returns the count of elements containing non-consequtive zeros in string of length n*/
unsigned int consZero(int n)
{
	// Base cases 
	if (n == 0)
		return 0;
	if (n == 1 || n == 2)
		return (prevConsqZero[n] = 1);
	if (prevConsqZero[n])
		return prevConsqZero[n];
	int k;
	if (n & 1)
		k = (n + 1) / 2;
	else
		k= n / 2;

/*Finds the count of  elements containing non-consequtive zeros using Matrix method*/
	if (n & 1) {
		prevConsqZero[n] = (consZero(k)*consZero(k) + consZero(k - 1)*consZero(k - 1));
	}
	else
		prevConsqZero[n]=(2 * consZero(k - 1) + consZero(k))*consZero(k);

	return prevConsqZero[n];
}

/* Main Function */
int main()
{
	int t;
	
	/*printf("Number of times wants to test i.e. test cases ");*/
	scanf_s("%d", &t);

	for (int i = 1; i <= t; i++)
	{
		int n;
		scanf_s("%d", &n);
		unsigned int res = (consZero(n + 2) % M);

		printf("%u\n", res);
	}
	return 0;
}
