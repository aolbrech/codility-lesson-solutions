//Count the number of passing cars on the road
// --> Only count the couples (P, Q) with 0 <= P < Q < N when P is travelling east (0) and Q is travelling west (1)

#include <vector>
#include <iostream>

using namespace std;

int countPassingCars(vector<int> &myVector)
{
	//Step 1: Calculate the total sum of elements in this array (corresponds to counting all the cars heading west)
	unsigned int carsHeadingWest = 0;
	for(unsigned int i = 0; i < myVector.size(); ++i)
		carsHeadingWest += myVector[i];

	//Step 2: Now loop over the array and keep track for each car heading east, how many cars will be travelling west and thus be passed
	int passedCars = 0;
	for(unsigned int i = 0; i < myVector.size(); ++i)
	{
		if(myVector[i] == 1)
			carsHeadingWest -= 1;
		else
			passedCars += carsHeadingWest;
		if(passedCars > 1000000000)
			return -1;
	}

	return passedCars;
}

int main()
{
	int firstArray[] = {0, 1, 0, 1, 1}; 
	std::vector<int> firstVector(firstArray, firstArray +sizeof(firstArray)/sizeof(int));
	std::cout << " --> Number of passing cars is " << countPassingCars(firstVector) << std::endl;

	int secondArray[] = {1, 0, 0, 1, 1};
	std::vector<int> secondVector(secondArray, secondArray +sizeof(secondArray)/sizeof(int));
	std::cout << " --> Number of passing cars is " << countPassingCars(secondVector) << std::endl;

	int thirdArray[] = {1, 1, 0, 1, 1}; 
	std::vector<int> thirdVector(thirdArray, thirdArray +sizeof(thirdArray)/sizeof(int));
	std::cout << " --> Number of passing cars is " << countPassingCars(thirdVector) << std::endl;

	int fourthArray[] = {0, 0, 0, 0, 0}; 
	std::vector<int> fourthVector(fourthArray, fourthArray +sizeof(fourthArray)/sizeof(int));
	std::cout << " --> Number of passing cars is " << countPassingCars(fourthVector) << std::endl;}
