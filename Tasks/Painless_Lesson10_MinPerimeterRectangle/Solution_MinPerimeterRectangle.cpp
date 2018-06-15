//Find the minimal perimeter of any rectangle whose area equals N
//--> Same as finding the nrDivisors, but now just add the value of i and its symmetric divisor to calculate the perimeter

#include <iostream>
#include <algorithm>

int main()
{
	int N = 30;

    int i = 1;
    int minPerimeter = 2*N+2;
    while(i*i <= N)
    {
        if(N%i == 0)
            minPerimeter = std::min(minPerimeter, 2*(i+N/i));
        i++;
    }
	
	std::cout << " The minimal perimeter of any rectangle whose area equals " << N << " is: " << minPerimeter << std::endl;

    return 0;
}
