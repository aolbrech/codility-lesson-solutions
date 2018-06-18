//Given a string containing words, find the longest word that specifies specific conditions

#include <algorithm>
#include <cctype>
#include <locale>
#include <vector>
#include <string>
#include <iostream>

using namespace std;

int getLongestPasswordSize(string &S) {
    // write your code in C++14 (g++ 6.2.0)
    
    //Determine the number of different words
    int nrOfWords = 1;
    for(unsigned int i = 0; i < S.size(); ++i)
    {
        if(isspace(S[i]))
            nrOfWords++;
    }

    vector<string> possibleWords(nrOfWords);
    int startIndex = 0, wordIndex = 0;
    for(unsigned int i = 0; i < S.size(); ++i)
    {
        if(isspace(S[i]) || i == S.size()-1)
        {
            int endPoint = i-1;
            if(i == S.size()-1)
                endPoint = i;  //Only need the -1 in case a space is encountered!!
            possibleWords[wordIndex] = S.substr(startIndex, endPoint-startIndex+1);  //going from n to i ~ n-i+1 (+1 since you want n also!!)
            startIndex = i+1;
            wordIndex++;
        }
    }

    //Now loop over the different words and check whether they are correct
    int longestPasswordSize = -1;
    for(unsigned int i = 0; i < possibleWords.size(); ++i)         //Looping over all the different words
    {
        bool correctPassword = true;
        int nrDigits = 0, nrLetters = 0;
        std::string currentPassword = possibleWords[i];
        for(unsigned int j = 0; j < currentPassword.size(); ++j)   //Looping over all the letters in each of the words
        {  
            if(!isalnum(currentPassword[j]))
            {
                correctPassword = false;
                break;    //Stops the letter loop!
            }
            else if(isdigit(currentPassword[j]))
                nrDigits++;
            else if(isalpha(currentPassword[j]))
                nrLetters++;
        }
        if(nrDigits%2 == 0 || nrLetters %2 != 0)
            correctPassword = false;
        if(correctPassword)
            longestPasswordSize = max(longestPasswordSize, (int)currentPassword.size());
    }

    return longestPasswordSize;
}

int main()
{
	std::string myString = "test 5 a0A pass007 ?xy1";
	std::cout << " The longest correct password in this string is: " << getLongestPasswordSize(myString) << std::endl;
	
	return 0;
}
