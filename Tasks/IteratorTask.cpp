#include <iostream>
#include <string>
#include <vector>
#include <istream>

using namespace std;

class Solution{
  public:
    Solution(std::vector<int>& v);
    Solution(std::vector<string>& v);
    Solution(string& s);
    
    class iteratorString;
    iteratorString beginS();
    iteratorString endS();
    
    class iteratorInt;
    iteratorInt beginI();
    iteratorInt endI();

  private:
    std::vector<string> m_dataS;
    std::vector<int> m_dataI;
};

Solution::Solution(string& inputData)
{
    //Loop over the data in the istream given as input, and only extract the correct integers
    std::vector<string> possibleNumbers;
    for(unsigned int i = 0; i < inputData.size(); ++i)
    {
        std::string posNr;
        if(inputData[i] == '/')
            std::cout << " Looking at character: " << inputData[i] << std::endl;
    }
    
}

Solution::Solution(std::vector<string>& vector)
{
    m_dataS = vector;
}

Solution::Solution(std::vector<int>& vector)
{
    m_dataI = vector;
}

class Solution::iteratorString{
    string* value;
    public:
        iteratorString(string* x): value(x) {}
        bool operator!=(Solution::iteratorString it) {return value != it.value;}
        Solution::iteratorString operator++() {++value; return *this;}
        string& operator*() {return *value;}
};

class Solution::iteratorInt{
    int* value;
    public:
        iteratorInt(int* x): value(x) {}
        bool operator!=(Solution::iteratorInt it) {return value != it.value;}
        Solution::iteratorInt operator++() {++value; return *this;}
        int& operator*() {return *value;}
};

Solution::iteratorString Solution::beginS()
{
    return &m_dataS[0];
}

Solution::iteratorString Solution::endS()
{
    return &m_dataS[m_dataS.size()];
}

Solution::iteratorInt Solution::beginI()
{
    return &m_dataI[0];
}

Solution::iteratorInt Solution::endI()
{
    return &m_dataI[m_dataI.size()];
}

int main ()
{
    std::string myText;
    myText = "137 /n";
    myText += "-104 /n";
    myText += "2 58 /n";
    myText += "  +0 /n";
    myText += "++3 /n";
    myText += "+1 \n";
    myText += " 23.9 /n";
    myText += "2000000000 /n";
    myText += "-0 \n";
    myText += "five /n";
    myText += " -1 \n";
    std::cout << myText << std::endl;
   
	string myStrings[] = {"string1", "string2", "string3", "string4", "string5"};
    std::vector<string> myVector (myStrings, myStrings + sizeof(myStrings) / sizeof(std::string) );
    Solution sol(myVector);
    for(Solution::iteratorString it = sol.beginS(); it != sol.endS(); ++it)
    {
        string x = *it;
        cout << x << endl;
    }
    
    int myInts[] = {1, 2, 3, 4, 5};
	std::vector<int> myVectorInts(myInts, myInts+sizeof(myInts)/sizeof(int));
    Solution solInt(myVectorInts);
    for(Solution::iteratorInt it = solInt.beginI(); it != solInt.endI(); ++it)
    {
        int x = *it;
        cout << x << endl;
    }
    
    return 0;
}
