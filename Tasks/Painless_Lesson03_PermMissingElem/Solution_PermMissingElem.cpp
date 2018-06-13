// Find the missing element in a given permutation
// Find the missing element in an array with N elements in the range A[1 ... N+1]
//
// Time worst-case O(N) and space worst-case O(1)

#include <iostream>
#include <vector>

using namespace std;

double factorial(int n)
{
	if(n == 0 || n == 1)
		return 1;
	else
		return factorial(n-1)*n;
}

int findMissingElement(vector<int> &myVector)
{
	double product = 1;
	int highestElement = myVector.size()+1;
	unsigned int factorialOfArray = factorial(highestElement);
	for(unsigned int i = 0; i < myVector.size(); ++i)
		product *= myVector[i];

	return (int)factorialOfArray/product;
}

//Can avoid using factorial by using the sum, which will behave better for large numbers
int findMissingElement_Sum(vector<int> &myVector)
{
	unsigned long long sumOfArray = 0;
	unsigned long long highestElement = myVector.size()+1;
	unsigned long long sumWithoutMissingElem = (highestElement+1)*highestElement/2;
	for(unsigned int i = 0; i < myVector.size(); ++i)
		sumOfArray += myVector[i];

	return (sumWithoutMissingElem - sumOfArray);
}

int main()
{
	int myArray[] = {1, 3, 6, 4, 7, 2, 10, 12, 9, 11, 8};
	std::vector<int> myVector (myArray, myArray + sizeof(myArray) / sizeof(int) );
	
	int missingElement = findMissingElement(myVector);
	std::cout << " The missing element in the given array is: " << missingElement << " (Should be 5)" << std::endl;
}
