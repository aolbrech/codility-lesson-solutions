//Compute the number of integers that are divisible by K in the range [a ... b]

#include <iostream>
#include <vector>

using namespace std;

int getNumberOfInts(int A, int B, int K)
{
	//Step 1: Identify the first divisble number in the range
	int firstDivInt = A;
	if(A%K != 0)
		firstDivInt = A+(K-(A%K));

	//Step 2: Identify the last divisible number in the range
	int lastDivInt = B;
	if(B%K != 0)
		lastDivInt = B-(B%K);
	if(lastDivInt < firstDivInt)
		return 0;

	//Step 3: Divide the difference of these two integers by K
	return ((lastDivInt-firstDivInt)/K+1);
}

int main()
{
	int A = 6, B = 11, K = 2;
	std::cout << " Number of integers that are divisible by " << K << " between " << A << " and " << B << " are: " << getNumberOfInts(A, B, K) << std::endl; 

	A = 0, B = 0, K = 1;
	std::cout << " Number of integers that are divisible by " << K << " between " << A << " and " << B << " are: " << getNumberOfInts(A, B, K) << std::endl; 

	A = 0, B = 2000000000, K = 2;
	std::cout << " Number of integers that are divisible by " << K << " between " << A << " and " << B << " are: " << getNumberOfInts(A, B, K) << std::endl; 

	A = 2, B = 5, K = 10;
	std::cout << " Number of integers that are divisible by " << K << " between " << A << " and " << B << " are: " << getNumberOfInts(A, B, K) << std::endl; 
	
	A = 11, B = 354, K = 17;
	std::cout << " Number of integers that are divisible by " << K << " between " << A << " and " << B << " are: " << getNumberOfInts(A, B, K) << std::endl; 
}
