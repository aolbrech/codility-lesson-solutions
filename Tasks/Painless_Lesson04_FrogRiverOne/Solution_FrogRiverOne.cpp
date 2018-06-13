//Find the earliest time when a frog can jump to the other side of a river

#include <vector>
#include <iostream>

using namespace std;

void printCounter(int myArray[], int length)
{
	for(int i = 0; i < length; ++i)
		std::cout << " " << myArray[i];
	std::cout << " " << std::endl;
}

int getEarliestJumpTime(vector<int> &myVector, int lengthOfRiver)
{
	//Create a counter of all elements that starts at 0 and is set to 1 once a first leave on this position has fallen
	int fallenLeavesCounter[lengthOfRiver] = {0};   //Create an array from 0 to X-1 with all 0s
	int sumOfCounter = lengthOfRiver;
	int sizeOfVector = myVector.size();

	for(int i = 0; i < sizeOfVector; ++i)
	{
		if(fallenLeavesCounter[myVector[i]-1] != 1)
		{
			fallenLeavesCounter[myVector[i]-1] = 1;
			sumOfCounter -= 1;
		}
		if(sumOfCounter == 0)
			return i;
	}
	
	return -1;
}

int main()
{
	int arrayA[] = {1, 3, 1, 4, 2, 3, 5, 4};
	std::vector<int> myVector (arrayA, arrayA + sizeof(arrayA) / sizeof(int) );
	int lengthOfRiver = 5;

	int earliestTime = getEarliestJumpTime(myVector, lengthOfRiver);
	if(earliestTime != -1)
		std::cout << " The frog can jump over the river after " << earliestTime << " seconds" << std::endl;
	else
		std::cout << " The frog will not be able to jump over the river given the configuration of falling leaves ... " << std::endl;
}
