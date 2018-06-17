//Divide array A into K blocks and minimize the largest sum of any block
//--> Use a binary search algorithm where the sorted list corresponds to the list of 'largest sums' possible

#include <vector>
#include <iostream>

using namespace std;

bool realisticConfig(int maxValue, vector<int> array, int maxNumberOfBlocks)
{
    int sumOfBlock = 0;
    int nrOfCreatedBlocks = 1;  //At least A[1] will go in the first block, so start with 1
    for(unsigned int i = 0; i < array.size(); ++i)
    {
        sumOfBlock += array[i];
        
        //Once the created block has a sum greater than maxValue, it should be split and a new block should be created
        if(sumOfBlock > maxValue)
        {
            nrOfCreatedBlocks++;      //Starting block number 2, 3, ... here since A[i] goes into a new block!!
            sumOfBlock = array[i];
            if(nrOfCreatedBlocks > maxNumberOfBlocks)   
                return false;     
        }
    }
    return true;
}

int getMinimalSum(int K, int M, vector<int> &A) {
    
    //Determine the lower and upper limit for the binary search algorithm
    int maxElement = 0;
    int sumArray = 0;
    for(unsigned int i = 0; i < A.size(); ++i)
    {
        maxElement = max(maxElement, A[i]);
        sumArray += A[i];
    }
    
    //Apply the binary search algorithm on the list between maxElement (~{max(A)}) and sumArray (~{A})
    int lowerLimit = maxElement;
    int upperLimit = sumArray;
    
    //This is the 'largest sum' value for which will be evaluated whether it is a realistic configuration given the pre-requisites!
    int mid = 0; 
    int result = sumArray;          
    while(lowerLimit <= upperLimit)
    {
        mid = (lowerLimit+upperLimit)/2;
        if(realisticConfig(mid, A, K))   //If this is a possible configuration, smaller mid-value should still be possible
        {
            upperLimit = mid-1;
            result = mid;
        }
        //The results obtained in this else are not any realistic configurations, so the last previous one should be taken as final result
        else
            lowerLimit = mid+1;  
    }
    
    return result;   //Should pay attention which value is returned, (lowerLimit+upperLimit)/2 is not correct!!
}

int main()
{
	int K = 3;
	int M = 5;  //--> Not used, just info for the order calculation!
	int myArray[] = {2, 1, 5, 1, 2, 2, 2};
	std::vector<int> myVector (myArray, myArray + sizeof(myArray) / sizeof(int) );

	std::cout << " The minimal 'largest sum' that can be found by dividing this array into " << K << " blocks is: " << getMinimalSum(K, M, myVector) << std::endl;
	return 0;
}
