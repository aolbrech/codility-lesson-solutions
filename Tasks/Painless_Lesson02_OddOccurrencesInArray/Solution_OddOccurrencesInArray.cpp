//Create a function that finds the value in an array with an uneven number of integers that cannot be paired to any of the other elements
// [a, b, a, c, b, d, c] --> Should give the value d

#include <iostream>
#include <vector>
#include <map>
#include <functional>

int findOddOccurrenceInArray_BruteForce(std::vector<int> &myVector)   //Brute-force method requiring O(n2) for time complexity ...
{	
	int nonPairedElement = myVector[0];

	for(unsigned int i = 0; i < myVector.size(); ++i)
	{
		int nrOfTimesInArray = 0;
		for(unsigned int j = 0; j < myVector.size(); ++j)
		{
			if(myVector[j] == myVector[i])
				nrOfTimesInArray++;
		}
		if(nrOfTimesInArray%2 != 0)
			return myVector[i];
	}	
	
	return nonPairedElement;
}

int findOddOccurrenceInArray_Hashing(std::vector<int> &myVector)    //Using hashing a double for-loop is not required anymore, but extra space for the hash table is needed
{
	std::map<int, int> countOccurrences;
	for(unsigned int i = 0; i < myVector.size(); ++i)
	{
		if(countOccurrences.find(myVector[i]) == countOccurrences.end())
		{
			countOccurrences.insert(std::pair<int, int>(myVector[i], 1));
		}
		else
			countOccurrences[myVector[i]]++;
	}
	
	for(std::map<int, int>::iterator it = countOccurrences.begin(); it != countOccurrences.end(); ++it)
	{
		if((it->second)%2 != 0)
			return it->first;
	}
	return myVector[0];
}

//a ^ b = 0 if a and b are eqaul, 1 otherwise
// ==> Can use bitwise xor to go through entire list since a ^ b ^ a = b
int findOddOccurrenceInArray_Bitwise(std::vector<int> &myVector)
{
	int xorTotal = 0;
	for(unsigned int i = 0; i < myVector.size(); ++i)
		xorTotal = xorTotal^myVector[i];
	return xorTotal;
}

int main()
{
	int myArray[] = {1, 1, 4, 4, 3, 3, 4};
	std::vector<int> myVector (myArray, myArray + sizeof(myArray) / sizeof(int) );
	int oddOccurrence_BF = findOddOccurrenceInArray_BruteForce(myVector);
	int oddOccurrence_Hashing = findOddOccurrenceInArray_Hashing(myVector);
	int oddOccurrence_Bitwise = findOddOccurrenceInArray_Bitwise(myVector);
	std::cout << " --- Expected result for this array is 4 " << std::endl;
	std::cout << " --- Found results are: " << oddOccurrence_BF << " (BF method), " << oddOccurrence_Hashing << " (using extra space), " << oddOccurrence_Bitwise << " (using bitwise xor) " << std::endl;

	int myOtherArray[] = {9, 3, 9, 3, 9, 7, 9};
	std::vector<int> myOtherVector (myOtherArray, myOtherArray + sizeof(myOtherArray) / sizeof(int) );
	int oddOccurrenceOther_BF = findOddOccurrenceInArray_BruteForce(myOtherVector);
	int oddOccurrenceOther_Hashing = findOddOccurrenceInArray_Hashing(myOtherVector);
	int oddOccurrenceOther_Bitwise = findOddOccurrenceInArray_Bitwise(myOtherVector);
	std::cout << "\n --- Expected result for this array is 7 " << std::endl;
	std::cout << " --- Found results are: " << oddOccurrenceOther_BF << " (BF method), " << oddOccurrenceOther_Hashing << " (using extra space), " << oddOccurrenceOther_Bitwise << " (using bitwise xor) " << std::endl;
}
