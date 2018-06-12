// Code written in C
// Correctness: 100 %
// Performance: Not assessed
// Time Complexity: O(log(N))
// Space Complexity: O(1)

#include <stdio.h>

int solution(int N) {
    int longestBinaryGap = 0;
    int currentBinaryGap = -1;
    
    int val = N;
    
    while (val != 0) {
        if ((val & 1) == 1) {
            if (longestBinaryGap < currentBinaryGap) {
                longestBinaryGap = currentBinaryGap;
            }
            
            currentBinaryGap = 0;
        } else if (currentBinaryGap != -1) {
            ++currentBinaryGap;
        }
        
        val = val >> 1;
    }
    
    return longestBinaryGap;
}

int main(void)
{
	int integerValue = 1041;
	int mySolution = solution(integerValue);
	printf("Found as solution %d \n", mySolution);
	return 0;
}
