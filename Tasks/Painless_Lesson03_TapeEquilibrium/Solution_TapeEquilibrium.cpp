//Find the minimal value for |(A[0] + ... + A[P-1])-(A[P] + ... + A[N-1])| for a specific value of P
//This point corresponds to splitting the tape into two non-empty parts

#include <iostream>
#include <vector>
#include <cstdlib>

using namespace std;

int minimizeSplitting(vector<int> &myVector)
{
	//Step 1: Determine the total sum of elements of this vector
	long long totalSumOfElements = 0;	
	for(unsigned int i = 0; i < myVector.size(); ++i)
		totalSumOfElements += myVector[i];

	//Step 2: Now go through the entire vector again, and calculate this difference
	long long passedSum = myVector[0];
	unsigned long long minimalValue = abs(2*passedSum - totalSumOfElements);   //Cannot just take abs(totalSumOfElements) as starting value --> Issue for [-1000, 1000]	!!
	for(unsigned int i = 1; i < myVector.size(); ++i)
	{
		unsigned long long currentDiff = abs(2*passedSum - totalSumOfElements);
		if(currentDiff < minimalValue)
			minimalValue = currentDiff;
		passedSum += myVector[i];
	}
	return minimalValue;
}

int main()
{
	int myArray[] = {3, 1, 2, 4, 3};
	std::vector<int> myVector (myArray, myArray + sizeof(myArray) / sizeof(int) );

	int minimizedValue = minimizeSplitting(myVector);
	std::cout << " Found as minimized value for splitting the tape: " << minimizedValue << std::endl;	

	std::vector<int> largeVector;
	for(int i = 0; i < 40000; ++i)
		largeVector.push_back(rand() % 2000 - 1000);
	std::cout << " Found as minimized value for splitting the large array: " << minimizeSplitting(largeVector) << std::endl;

	int myArray_TwoElems[] = {-1000, 1000};
	std::vector<int> myVector_TwoElems (myArray_TwoElems, myArray_TwoElems + sizeof(myArray_TwoElems) / sizeof(int) );
	std::cout << " For vector [-1000, 1000] found as solution: " << minimizeSplitting(myVector_TwoElems) << std::endl;
}
