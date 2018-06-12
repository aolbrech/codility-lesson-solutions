// you can use includes, for example:
// #include <algorithm>
#include <vector>
#include <iostream>
#include <cstdlib>
#include <string>

using namespace std;

//Get the binary representation of any integer in integer form
string binaryRepresentationOfInt(int integerValue)
{

	int myInt = integerValue;  //Cannot pass an integer as reference, so need to create a copy
	string myBinary = "";
	while(myInt > 0)
	{
		//myBinaryValue = (myInt%2)*currentPowerForBinary+myBinaryValue;
		if(myInt%2 == 0)
			myBinary = "0"+myBinary;
		else
			myBinary = "1"+myBinary;
		myInt = myInt / 2;
	}
    return myBinary;
}

int binaryGapOfInt(int integerValue)
{
	int myInt = integerValue;
	int previousBinaryValue = myInt%2;
	int largestGap = 0, currentGap = 0;                  
	
	while(myInt > 0)
	{
		int currentBinaryValue = (myInt%2);
		if( (currentBinaryValue) != previousBinaryValue)
		{
			if(currentBinaryValue == 1)
			{
				if (currentGap > largestGap) 
					largestGap = currentGap;
				currentGap = 0; //Reset the gap counter
			}
			else if(currentBinaryValue == 0)
				currentGap++;
		}
		else if(currentBinaryValue == 0 && currentGap != 0) //Automatically applies that also previousBinaryValue is 0
			currentGap++;

		myInt = myInt / 2;
		previousBinaryValue = currentBinaryValue;
	}
	
	return largestGap;
}

int main()
{

	const int numberOfElements = 9;
	int testArray[numberOfElements] = {9, 529, 20, 15, 1041, 561892, 74901729, 1376796946, 301};
	int testArrayResults[numberOfElements] = {2, 4, 1, 0, 5, 3, 4, 5, 2};
	for(int i = 0; i < numberOfElements; i++)
		std::cout << " Binary representation of " << testArray[i] << " is " << binaryRepresentationOfInt(testArray[i]) << " which has as BinaryGap " << binaryGapOfInt(testArray[i]) << " (Expected = " << testArrayResults[i] << ")" << std::endl;
	return 0;
}
