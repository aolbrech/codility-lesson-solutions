//Count factors of a given n
// --> Same as first example in Lesson 10 (count nr divisors)
//
//Remark: Solution is not using the correct datatype --> Issue if N = 1*10^9

#include <iostream>

using namespace std;

int main()
{    
	int N = 24;

    int i = 1;
    int nrFactors = 0;
    while(i*i <= N)
    {
        if(N%i == 0)
        {
            nrFactors++;
            if(N/i != i)
                nrFactors++;
        }
        i++;
    }

	std::cout << " Found " << nrFactors << " factors for N = " << N << std::endl;
    return 0;
}
