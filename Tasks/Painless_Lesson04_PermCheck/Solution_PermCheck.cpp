//Check whether array A is a permutation

#include <vector>
#include <iostream>
#include <cstdlib>

using namespace std;

int isArrayPerm(vector<int> &myVector)
{
	//Similar approach to the demo example with the missing integer
	int vectorSize = myVector.size();
	for(int i = 0; i < vectorSize; ++i)
	{
		if(abs(myVector[i]) >= 1 && abs(myVector[i]) <= vectorSize)
		{
			if(myVector[abs(myVector[i])-1] > 0)
				myVector[abs(myVector[i])-1] = -myVector[abs(myVector[i])-1];
			else
				return 0; //Element myVector[i] occurs more than once in the array ...
		}
		else
			return 0; //All elements in the array should lie between 1 and N
	}
	
	return 1;
}

int main()
{
	int arrayA[] = {3, 4, 5, 4};
	std::vector<int> vectorA (arrayA, arrayA + sizeof(arrayA) / sizeof(int) );
	std::cout << " --> Is this vector a permutation: " << isArrayPerm(vectorA) << std::endl;

	int arrayB[] = {1, 4, 2, 3};
	std::vector<int> vectorB (arrayB, arrayB + sizeof(arrayB) / sizeof(int) );
	std::cout << " --> Is this vector a permutation: " << isArrayPerm(vectorB) << std::endl;
}
