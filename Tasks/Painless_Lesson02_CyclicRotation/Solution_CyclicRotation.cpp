//Create a function that rotates an array to the right by a given number of steps
// [a, b, c, d] --> [d, a, b, c] ...
#include <vector>
#include <iostream>

using namespace std;

vector<int> cyclicRotation(vector<int> &myVector, int nrOfRightShifts)
{
	unsigned int lengthOfVector = myVector.size();
	vector<int> shiftedVector = myVector;

	for(unsigned int vectorIndex = 0; vectorIndex < lengthOfVector; ++vectorIndex)
	{
		if( (vectorIndex + nrOfRightShifts) < lengthOfVector-1)    //New index still lies within vector range, so just replace the value
			shiftedVector[vectorIndex+nrOfRightShifts] = myVector[vectorIndex];
		else
			shiftedVector[(vectorIndex+nrOfRightShifts)%lengthOfVector] = myVector[vectorIndex];
	}
	return shiftedVector;
}

int main()
{
	int nrShifts = 1;
	int myArray[] = {1, 3, 6, 4, 1, 2};
	std::vector<int> myVector (myArray, myArray + sizeof(myArray) / sizeof(int) );

	std::vector<int> shiftedVector = cyclicRotation(myVector, nrShifts);

	std::cout << " Found as solution the following array: ";
	for(unsigned int i = 0; i < shiftedVector.size(); ++i)
		std::cout << shiftedVector[i] << " ";
	std::cout << "  " << std::endl;
}
