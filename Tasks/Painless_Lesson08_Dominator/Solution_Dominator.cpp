//Find an index of an array such that its value occurs more than half of indices in array

#include <vector>
#include <iostream>

using namespace std;

int getIndex(vector<int> &A) 
{   
    //Make use of the fact that if 2 distinct values are removed from an array, this doesn't influence the leader value of the remaining array
    int sizeOfKeptValues = 0;
    int lastKeptValue = 0;       //Initialized value doesn't matter, for an empty array the value is stored anyways
    for(unsigned int i = 0; i < A.size(); ++i)
    {
        if(sizeOfKeptValues == 0)
        {
            sizeOfKeptValues++;
            lastKeptValue = A[i];
        }
        else
        {
            if(lastKeptValue == A[i])    //Dealing with non-distinct values, so cannot remove them
            {
                sizeOfKeptValues++;
                //lastKeptValue = A[i];  //--> Doesn't actually do anything, because lastKeptValue is already equal to A[i] !!
            }
            else
                sizeOfKeptValues--;
        }
    }
    
    //The lastKeptValue is now a candidate for the leader value, but have to count whether this one occurs more than half of the elements
    int leaderCandidate = lastKeptValue;
    if(sizeOfKeptValues == 0)
        return -1;
    
    int leaderIndex = 0;
    int count = 0;
    for(unsigned int i = 0; i < A.size(); ++i)
    {
        if(A[i] == leaderCandidate)
        {
            count++;
            leaderIndex = i;
        }
    }
    
    if(count > (int)(A.size()/2))
        return leaderIndex;
    
    return -1;
}

int main()
{
	int myArray[] = {3, 4, 3, 2, 3, -1, 3, 3};
	std::vector<int> myVector (myArray, myArray + sizeof(myArray) / sizeof(int) );

	int foundIndex = getIndex(myVector);
	if(foundIndex != -1)
		std::cout << " The element that occurs more than half of the time in the array can be found on position: " << foundIndex << std::endl;
	else
		std::cout << " None of the elements occurs more than half of the time in the considered array ... " << std::endl;

	return 0;
}
