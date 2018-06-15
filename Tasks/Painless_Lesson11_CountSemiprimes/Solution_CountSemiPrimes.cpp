//Count the semiprime numbers in the range [a .. b]

#include <iostream>
#include <vector>
#include <cstdlib>

using namespace std;

vector<int> getNrSemiPrimes(int N, vector<int> &P, vector<int> &Q) {
    // write your code in C++14 (g++ 6.2.0)
    
    //Step 1: Use factorization to store the smallest prime that divides this number
    vector<int> smallestPrime(N+1, 0);
    int i = 2; //0 and 1 are excluded from the prime-number calculation
    while(i*i <= N) //Only need to look at the first sqrt(N) values because if a is a divisor, N/a as well
    {
        if(smallestPrime[i] == 0)
        {
            int k = i*i;
            while(k <= N)
            {
                if(smallestPrime[k] == 0)
                    smallestPrime[k] = i;
                k += i;
            }
        }
        i++;
    }
    //--> O(N*loglogN)

    //Now loop over the list of smallestPrimes and create a prefix sum for the number of semiprimes
    vector<int> prefixSums(N+1, 0);
    for(int i = N; i > 0; i--)  
    {
        prefixSums[i-1] = prefixSums[i];
        if(i >2 && abs(smallestPrime[i]) > 0 && smallestPrime[i/smallestPrime[i]] == 0)
            prefixSums[i-1]++;
    }
    //--> O(N)
    
    vector<int> nrOfSemiPrimes(P.size(), 0);  //--> Vector of O(M)
    for(unsigned int p = 0; p < P.size(); ++p)
    {
        //Get the slice between P[i] and Q[i]
        //--> Since the prefix sums is stored backward a_x + .. + a_y = prefix[y] - prefix[x-1]
        nrOfSemiPrimes[p] = prefixSums[P[p]-1] - prefixSums[Q[p]];
    }
    //--> O(M)

    return nrOfSemiPrimes;
}

int main()
{
	int N = 26;
	int p[] = {1, 4, 16};
	std::vector<int> P (p, p + sizeof(p) / sizeof(int) );
	int q[] = {26, 10, 20};
	std::vector<int> Q (q, q + sizeof(q) / sizeof(int) );

	std::vector<int> solution = getNrSemiPrimes(N, P, Q);
	std::cout << " Found as solution the following number of semiprimes: ";
	for(unsigned int i = 0; i < solution.size(); ++i)
		std::cout << solution[i] << " ";
}
