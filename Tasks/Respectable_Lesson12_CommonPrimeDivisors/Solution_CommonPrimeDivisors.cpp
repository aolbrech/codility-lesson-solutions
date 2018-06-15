//Check whether two numbers have the same prime divisors
//--> In order to achieve O(Z*log(max(A)+max(B))^2) the greatest common divisor should be used
// ==> Should exploit that the gcd contains all of the common prime divisors of a and b

#include <vector>
#include <iostream>
#include <cstdlib>

using namespace std;

bool checkForPrimality_TooSlow(int n)
{
    //Special cases for 1 and 0, which are neither prime nor composite
    if(n==1 || n == 0)
        return false;
        
    int i = 2;
    while(i*i <= n)
    {
        if(n%i == 0)
            return false;
        i++;
    }
    return true;
}

vector<int> getPrimeDivisors_TooSlow(int n)
{
    vector<int> listOfDivisors;
    int i = 1;
    while(i*i <= n)
    {
        if(n%i == 0)
        {
            if(checkForPrimality_TooSlow(i))
                listOfDivisors.push_back(i);
            if(i*i != n && checkForPrimality_TooSlow(n/i))
                listOfDivisors.push_back(n/i);
        }
        i++;
    }

    return listOfDivisors;
}

//-- Functions used for optimal solution --//
int getGCD(int a, int b)   //a > b --> Since you use gcd(b, a mod b): Second value is most of the time smaller anyway
{
    int highestValue = a, lowestValue = b;
    if(a < b)
    {
        highestValue = b; lowestValue = a;
    }

    if(highestValue % lowestValue == 0)
        return lowestValue;
        
    else
        return getGCD(lowestValue, highestValue%lowestValue);
}

//-- Functions used for optimal solution --//
bool extraPrimeFactorExists(int n, int gcd)
{
    int rem = n/gcd;
    int GCD = gcd;
    while(rem != 1)               //Loop that is being performed a constant number of times, not n number of times!!
    {
        GCD = getGCD(GCD, rem);
        if(GCD == 1)
            return true;
        rem = rem/GCD;
    }
    return false;
}

int main() 
{
    int N = 26;
	int a[] = {15, 10, 3};
	std::vector<int> A (a, a + sizeof(a) / sizeof(int) );
	int b[] = {75, 30, 5};
	std::vector<int> B (b, b + sizeof(b) / sizeof(int) );

	//First try for solution: Get the list of prime divisors for each of the values and compare
	// --> Results in time-complexity of O(Z*(max(A)+max(B)))  ==> Too slow ... !!!
    int counter_TooSlow = 0;
    for(unsigned int i = 0; i < A.size(); ++i)
    {
        if(getPrimeDivisors_TooSlow(A[i]) == getPrimeDivisors_TooSlow(B[i]))
            counter_TooSlow++;
    }
    
	std::cout << " For the given set of arrays A and B, the elements A[i],B[i] have " << counter_TooSlow << " time(s) the same set of prime divisors " << std::endl;

	//Optimal solution: 
	//Since gcd contains all the common prime numbers of a and b, so a/gcd and b/gcd should only contain prime numbers already contained in gcd
	// ==> gcd(gcd, a/gcd) cannot become 1 !!!!
    int counter = 0;
    for(unsigned int i = 0; i < A.size(); ++i)
    {
        //Determine the gcd between A[i] and B[i]
        int gcd = getGCD(A[i], B[i]);

        //Once the gcd is known, it should be determined whether the remaining product A[i] = gcd*rem contains any prime numbers different than the ones included in the gcd. If this is the case, A[i] and B[i] do not have the same set of prime divisors
        if(extraPrimeFactorExists(A[i], gcd))
            continue;
        if(extraPrimeFactorExists(B[i], gcd))
            continue;
        
        counter++;
    }
	std::cout << " For the given set of arrays A and B, the elements A[i],B[i] have " << counter << " time(s) the same set of prime divisors " << std::endl;
}
