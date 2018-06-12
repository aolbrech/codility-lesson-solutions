// you can use includes, for example:
// #include <algorithm>
#include <vector>
#include <iostream>
#include <cstdlib>

// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;

using namespace std;

int solution(vector<int> &A) {
    //Loop through array and store only positive values
    vector<int> posArray;
    for(unsigned int i =0; i < A.size();++i)
    {
        if(A[i] > 0)
            posArray.push_back(A[i]);
    }
    int newArraySize = posArray.size();
    
    //Loop over the positive array and when looking at element x, change the array[x-1] value to a negative value
    //Hence the original array will be converted into the array [neg value if 1 is in orig array, neg value if 2 is in orig array, ...]
    //So the first index with a positive value in this array, indicates that this element was not included in the original array.
    
    for(unsigned int j = 0; j < posArray.size(); ++j)
    {
        if( abs(posArray[j]) -1 < newArraySize && posArray[abs(posArray[j]) -1] > 0)
            posArray[abs(posArray[j]) -1] = -posArray[abs(posArray[j]) -1];
    }
    
    for(unsigned int k = 0; k < posArray.size(); ++k)
    {
        if(posArray[k] > 0)
            return k+1;
    }
    
    return posArray.size()+1;
}

int main()
{
	int myArray[] = {1, 3, 6, 4, 1, 2};
	std::vector<int> myVector (myArray, myArray + sizeof(myArray) / sizeof(int) );
	int mySolution = solution(myVector);
	std::cout << " Found as solution: " << mySolution << " !" << std::endl;
	return 0;
}
