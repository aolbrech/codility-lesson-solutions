//Find a maximal set of non-overlapping segments
//--> Should use a greedy algorithm and use: 
/*
	Consider any nonempty subproblem Sk and let a_m be an element with the earliest end time
	Then: a_m is included in some maximum-size subset of mutually compatible activities of Sk

	==> Should just always select the element with the smallest B[i] and count how many can be included to obtain the maximum size!!
*/

#include <vector>
#include <iostream>

using namespace std;

int determineMaxSubsetSize(vector<int> &A, vector<int> &B) {
    
    if(A.size() == 0)
        return 0;
    
    //Go through the set of segments and continously choose the one with the largest end position
    int maximumSizeSubset = 1;
    int endPos = B[0];
    for(unsigned int i = 1; i < B.size(); ++i)
    {
        if(A[i] > endPos)
        {
            endPos = B[i];
            maximumSizeSubset++;
        }
    }
    return maximumSizeSubset;
}

int main()
{
	int a[] = {1, 3, 7, 9, 9};
	std::vector<int> A (a, a + sizeof(a) / sizeof(int) );
	int b[] = {5, 6, 8, 9, 10};
	std::vector<int> B (b, b + sizeof(b) / sizeof(int) );

	std::cout << " The maximum size of a set of non-overlapping segments is: " << determineMaxSubsetSize(A, B) << std::endl;
	return 0;
}
