//In a given array, find the subset of maximal sum in which the distance between consecutive elements is at most 6
//--> Should count for each position the maximal sum to get there using the maximal sum information from the previous elements!

#include <vector>
#include <iostream>

using namespace std;

int getMaximalSum(vector<int> &A) {
    // write your code in C++14 (g++ 6.2.0)
    
    //Store for each of the elements 0 to N-1, what the maximum sum is to get there
    //--> Start at the 1 position, and check the different jumps that were possible to get to this position!
    vector<int> maxSumToGetTo(A.size(), 0);
    maxSumToGetTo[0] = A[0];
   
	int array[] = { 1, 2, 3, 4, 5, 6};
    vector<int> possibleJumps(array, array+sizeof(array)/sizeof(int));
    int gameEndPoint = A.size()-1;
    for(int i = 1; i <= gameEndPoint; ++i) //Cannot use unsigned int, since otherwise (i-possibleJumps[j]) gives an overflow when negative!!!
    {
        for(unsigned int j = 0; j < possibleJumps.size(); ++j)
        {
            if((i - possibleJumps[j]) >= 0)
            {
                if(maxSumToGetTo[i] == 0)
                    maxSumToGetTo[i] = maxSumToGetTo[i-possibleJumps[j]]+A[i];
                else
                    maxSumToGetTo[i] = max(maxSumToGetTo[i], maxSumToGetTo[i-possibleJumps[j]]+A[i]);
            }
        }
    }
    
    return maxSumToGetTo[gameEndPoint];
}

int main()
{
	int myArray[] = {1, -2, 0, 9, -1, -2};
	std::vector<int> myVector (myArray, myArray + sizeof(myArray) / sizeof(int) );

	std::cout << " For the given array, the maximal sum to get across the board is: " << getMaximalSum(myVector) << std::endl;
	return 0;
}
