//Find a maximum sum of a compact subsequence of array elements
//--> Similar to the example in Lesson 09 but has to work for negative values as well!!

#include <vector>
#include <iostream>

using namespace std;

int main()
{
	int myArray[] = {3, 2, -6, 4, 0};
	std::vector<int> myVector (myArray, myArray + sizeof(myArray) / sizeof(int) );

    int maxSlice = myVector[0];
    int maxEnding = myVector[0];
    for(unsigned int i = 1; i < myVector.size(); ++i)
    {
        maxEnding = max(myVector[i], maxEnding+myVector[i]); //Get the max sum for a slice ending on a_i -->(a_o, ..., a_i), (a_1, ..., a_i), ... (a_i)
        maxSlice = max(maxSlice, maxEnding); //This checks whether the maxEnding for this element is larger than the current found maxSlice
    }

	std::cout << " The maximum sum of a compact subsequence of array elements is : " << maxSlice << std::endl;

    return 0;
}
