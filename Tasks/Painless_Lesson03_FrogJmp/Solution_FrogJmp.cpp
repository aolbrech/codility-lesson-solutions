//Count the minimal number of jumps from position X to Y

#include <cmath>
#include <iostream>

int getNumberOfJumps(int startPos, int endPos, int jumpDistance)
{
	double nrJumps = (double)(endPos-startPos)/jumpDistance;

	return ceil(nrJumps);
}

int main()
{
	int X = 10, Y = 85, D = 30;
	std::cout << " Minimal number of jumps required to go from X to Y is: " << getNumberOfJumps(X, Y, D) << std::endl;
}
