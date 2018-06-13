//Check whether a swap operation can be performed on two arrays of equal length n in such a way that the sum of elements are equal in both arrays.
// --> Swap operation: Picking one element from array A and exchanging it with one element from array B
//
// * Brute-force solution O(n^2): Check how the total sum changes while swapping every element
// * Best solution O(n): Count the difference between the sum of both arrays

#include <vector>
#include <iostream>

using namespace std;

bool swapPossible_BF(vector<int> &firstVector, vector<int> &secondVector)
{
	
	//Step 1: Calculate the sum of both vectors
	int sumFirstVect = 0, sumSecondVect = 0;
	int vectorSize = firstVector.size();
	for(int i = 0; i < vectorSize; ++i)
	{
		sumFirstVect += firstVector[i];
		sumSecondVect += secondVector[i];
	}
	
	//Step 2: Now do all the swaps and calculate how the sum changes
	for(int indexFirst = 0; indexFirst < vectorSize; ++indexFirst)
	{
		for(int indexSecond = 0; indexSecond < vectorSize; ++indexSecond)
		{
			int changeBySwap = secondVector[indexSecond] - firstVector[indexFirst];
			if(sumFirstVect+changeBySwap == sumSecondVect-changeBySwap)
				return true;
		}
	}
	return false;
	
}

bool swapPossible_Smart(vector<int> &firstVector, vector<int> &secondVector, const int maxValueOfElems)
{
	//Step 1: Calculate the sums
	int sumFirstVect = 0, sumSecondVect = 0;
	int vectorSize = firstVector.size();
	for(int i = 0; i < vectorSize; ++i)
	{
		sumFirstVect += firstVector[i];
		sumSecondVect += secondVector[i];
	}

	//Step 2: Only way a solution can be found is whether the difference between the 2 arrays is even
	//--> Motivation: Are looking for the value x for which holds sumA + x = sumB - x ==> x = (sumB-sumA)/2 --> Since the value x should be an integer, the sumB-sumA should be even!!!
	int diff = sumSecondVect - sumFirstVect;
	if(diff%2 != 0)
		return false;

	//Step 3: Store the information of the elements of one of the arrays in an array that counts the presence of each of the elements
	//--> Use the fact that you know that the element of one array should be swaped with an element equal to elem-diff/2, so this can be easily looked up when the array is converted into a counter array
	int firstVectCounter[maxValueOfElems+1] = {0};
	for(int i = 0; i < vectorSize; ++i)	
		firstVectCounter[firstVector[i]]++;
	
	//Now loop over the second vector and check whether the value B[i]-diff/2 exists in the first vector
	for(int i = 0; i < vectorSize; ++i)
	{	
		int swapValueToLookFor = secondVector[i] - diff/2;
		if( swapValueToLookFor >= 0 && swapValueToLookFor <= maxValueOfElems && firstVectCounter[swapValueToLookFor] != 0)   //Need the first two checks since limit values should give an error otherwise
			return true;

	}
	return false;	
}

int main()
{
	int arrayA[] = {3, 4, 5, 4};
	std::vector<int> vectorA (arrayA, arrayA + sizeof(arrayA) / sizeof(int) );
	int arrayB[] = {6, 2, 1, 7};
	std::vector<int> vectorB (arrayB, arrayB + sizeof(arrayB) / sizeof(int) );

	std::cout << " --> Checking whether element swap can result in equal sum of arrays: " << swapPossible_BF(vectorA, vectorB) << std::endl;
	std::cout << " --> Checking whether element swap can result in equal sum of arrays (smart) : " << swapPossible_Smart(vectorA, vectorB, 3) << std::endl;
}
