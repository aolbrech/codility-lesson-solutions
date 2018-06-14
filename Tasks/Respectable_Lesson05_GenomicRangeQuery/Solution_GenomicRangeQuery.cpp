//Find the minimal nucleotide from a range of sequence DNA

#include <vector>
#include <iostream>
#include <string>
#include <map>

using namespace std;

//Brute-force method that creates substrings and then loops over each of the substrings to calculate the minimal impact factor
// --> Results in O(N*M) behavior and thus gives a time-out when evaluating large strings
vector<int> getImpactFactors_DoubleLoop(string &S, vector<int> &P, vector<int> &Q) {
    // write your code in C++14 (g++ 6.2.0)
    
    //Store the impact factor of each of the nucleotides in an enum
    std::map<char, int> stringToImpactFactor;
	stringToImpactFactor['A'] = 1;
	stringToImpactFactor['C'] = 2;
	stringToImpactFactor['G'] = 3;
	stringToImpactFactor['T'] = 4;
    
    //Now go through the different sequences and store the minimal impact factor
    vector<int> minImpactFactors;
    for(unsigned int i = 0; i < P.size(); ++i)       //P.size = M --> O(M)
    {
        string substring = S.substr(P[i], (Q[i]-P[i]+1));
        
        int impactFactorForString = 4;
        for(unsigned int j = 0; j < substring.length(); ++j)   //Worst-case this is the entire string sequence --> O(n)
            impactFactorForString = min(impactFactorForString, stringToImpactFactor[substring[j]]);
        minImpactFactors.push_back(impactFactorForString);
    }

    return minImpactFactors;
}

//Optimal solution using prefix sums, but by first converting the array of strings into an array of impact factor values
//S = [S[0], S[1], ...] --> S' = [[#A, #C, #G, #T] in S[0], [#A, #C, #G, #T] in S[1], ...]
// --> This conversion allows to have as prefix sum the array: [[0, 0, 0, 0], [#A, #C, #G, #T] in S[0], [#A, #C, #G, #T] in S[0]S[1], ...]
// ==> Calculating the slice prefix[Y+1] - prefix[X] then easily gives the number of each nucleotide in S[X]...S[Y]
vector<int> getImpactFactors_Prefix(string &S, vector<int> &P, vector<int> &Q) {
    // write your code in C++14 (g++ 6.2.0)
    
    std::map<char, int> stringToImpactFactor;
	stringToImpactFactor['A'] = 1;
	stringToImpactFactor['C'] = 2;
	stringToImpactFactor['G'] = 3;
	stringToImpactFactor['T'] = 4;
    
    //Step 1: Store for each of the elements in the string S its corresponding impactFactor info [A, C, G, T]
    int convertStringToImpactFactor[S.length()][4] = {0};
    for(unsigned int i = 0; i < S.length(); ++i)                                //O(N)
    {
        convertStringToImpactFactor[i][stringToImpactFactor[S[i]]-1]++;
    }

    //Now use this information to get the real prefix information
    int prefix[S.length()+1][4] = {0};
    for(unsigned int i = 1; i < S.length()+1; ++i)                              //O(N)
    {
        for(int j = 0; j < 4; ++j)                                              //O(4) ==> Total of O(4N) = O(N)
            prefix[i][j] = prefix[i-1][j] + convertStringToImpactFactor[i-1][j];
    }

    vector<int> minimalImpactFactors;
    for(unsigned int i = 0; i < P.size(); ++i)                                  //O(M)
    {
        for(int j = 0; j < 4; j++)                                              //O(4) ==> Total of O(4M) = O(M)
        {
            if( prefix[Q[i]+1][j] - prefix[P[i]][j] > 0)
            {
                minimalImpactFactors.push_back(j+1);
                break;
            }
        }
	}
	return minimalImpactFactors;                                                 //--> Total time: O(N+M) 
}

int main()
{
	string DNASequence = "CAGCCTA";
	int p[] = {2, 5, 0};
	std::vector<int> P (p, p + sizeof(p) / sizeof(int) );
	int q[] = {4, 5, 6};
	std::vector<int> Q (q, q + sizeof(q) / sizeof(int) );

	vector<int> solution_DoubleLoop = getImpactFactors_DoubleLoop(DNASequence, P, Q);
	std::cout << " Found as minimal impact factors : ";
	for(unsigned int i = 0; i < solution_DoubleLoop.size(); ++i)
		std::cout << solution_DoubleLoop[i] << " ";
	std::cout << " " << std::endl;

	vector<int> solution_Prefix = getImpactFactors_Prefix(DNASequence, P, Q);
	std::cout << " Found as minimal impact factors : ";
	for(unsigned int i = 0; i < solution_Prefix.size(); ++i)
		std::cout << solution_Prefix[i] << " ";
	std::cout << " " << std::endl;}
