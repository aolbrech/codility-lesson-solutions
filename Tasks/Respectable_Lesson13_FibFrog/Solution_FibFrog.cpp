//Count the minimum number of jumps for a frog to get to the other side of a river

#include <vector>
#include <iostream>

using namespace std;

vector<int> getFibonacciNumbers(int maxValue)
{
    vector<int> fibonacciNrs;
    fibonacciNrs.push_back(1);  //Omit the 0 and the second 1, only want the unique jumps ...
    fibonacciNrs.push_back(2);
    int fibValue = fibonacciNrs[0]+fibonacciNrs[1];
    while(fibValue <= maxValue)
    {
        fibonacciNrs.push_back(fibValue);
        int nrOfStoredValues = fibonacciNrs.size();
        fibValue = fibonacciNrs[nrOfStoredValues-2]+fibonacciNrs[nrOfStoredValues-1];
    }
    return fibonacciNrs;
}

//Use the fact that at most log(N) fibonacci numbers exist for a sequence up to N!!
int calculateMinNrJumps(vector<int> &A) {
    // write your code in C++14 (g++ 6.2.0)
    
    int lengthOfRiver = A.size()+1;   //Starting shore is defined on position -1
    vector<int> possibleJumps = getFibonacciNumbers(lengthOfRiver);  //Jumping from shore to shore is maximal possible jump

	//1 and 2 are automatically added as jump option ==> 2 should be removed in the case of []
    if(lengthOfRiver < 2)
        possibleJumps.pop_back();

    if(lengthOfRiver == possibleJumps[possibleJumps.size()-1])  //Need A.size()+1 jumps to get from shore (~1) to shore (~A.size()+1)
        return 1;
    
    //Go through the entire river, and determine the minimum number of jumps to reach each of these locations
    vector<int> nrReqJumps(lengthOfRiver, 0);
    for(int i = 0; i < lengthOfRiver; ++i)
    {
        if(A[i] == 1 || i == lengthOfRiver-1)   //Only need to check the positions where the frog can get to ...
        {
            for(unsigned int j = 0; j < possibleJumps.size(); ++j)  //--> Loop of order log(N)!!
            {
                //Look for either the start shore position, or another intermediate position that has been reached previously by the frog
                if( i - possibleJumps[j] > -1 && nrReqJumps[i - possibleJumps[j]] != 0 )
                {
                    if(nrReqJumps[i] == 0)
                        nrReqJumps[i] = nrReqJumps[i - possibleJumps[j]]+1;
                    else
                        nrReqJumps[i] = min(nrReqJumps[i], nrReqJumps[i - possibleJumps[j]]+1);
                }
                else if(i - possibleJumps[j] == -1)
                    nrReqJumps[i] = 1;
            }
        }
    }
    if(nrReqJumps[lengthOfRiver-1] != 0)
        return nrReqJumps[lengthOfRiver-1];
    
    return -1;
}

int main()
{
	int myArray[] = {0, 0, 0, 1, 1, 0, 1, 0, 0, 0, 0};
	std::vector<int> myVector (myArray, myArray + sizeof(myArray) / sizeof(int) );

	std::cout << " To get from one shore to the other, minimum " << calculateMinNrJumps(myVector) << " jumps are required! " << std::endl;


}
