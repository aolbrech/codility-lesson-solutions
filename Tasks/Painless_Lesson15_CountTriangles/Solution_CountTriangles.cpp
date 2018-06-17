//Count the number of triangles that can be built from a given set of edges
//--> Use the fact that if (A[i], A[j], A[k]) form a triangle (with A sorted), then A[i] and A[j] also form a triangle with all elements between j and k!!
// ==> Task can be transformed into finding the largest possible k in the array such that they form a triangle with a given i and j!!
//
// --> Described by a nested loop of order 3, but the k value is only altered in the first loop given a total of O(N^2)

#include <algorithm>
#include <vector>
#include <iostream>

using namespace std;

int countNrTriangles(vector<int> &A) {
    
    if(A.size() < 3)
        return 0;
    
    //Step 1: Sort the array A such that the only triangular condition to be checked is: A[P] + A[Q] < A[R]
    std::sort(A.begin(), A.end());
    
    //Use that if A[i] and A[j] form a triangle with A[k], then A[i] and A[j] also form a triangle with all elements between j and k!!
    //==> Should look for the highest index k with which (i, j) still form a triangle!
    int nrTriangles = 0;
    for(unsigned int i = 0; i < A.size()-2; ++i)
    {
        unsigned int z = i+2;
        for(unsigned int j = i+1; j < A.size()-1; ++j )
        {
            while(z < A.size() && A[i]+A[j] > A[z])
                z++;
            nrTriangles += (z-1) - j;
        }
    }
    return nrTriangles;
}

int main()
{
	int myArray[] = {10, 2, 5, 1, 8, 12};
	std::vector<int> myVector (myArray, myArray + sizeof(myArray) / sizeof(int) );

	std::cout << " For the given array, a total of " << countNrTriangles(myVector) << " can be created! " <<std::endl;
	return 0;
}
