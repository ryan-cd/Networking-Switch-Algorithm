#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


struct mapping 
{
    string MAC;
    int pin;
};

vector<mapping> dictionary;

void switchAlgorithm(int inputPort, string fromAddress, string toAddress)
{
    int Pout = -1;
    // Step one
    if(stoi(fromAddress.substr(0,2)) % 2 != 0)
    {
        cout << "drop" << endl;
        return;
    }
    
    // Step two
    bool update = false;
    for(int i = 0; i < dictionary.size(); i++)
        if(dictionary[i].MAC == fromAddress)
        {
            dictionary[i].pin = inputPort;
            update = true;
            break;
        }
    
    if(!update)
    {
        dictionary.push_back(mapping());
        dictionary[dictionary.size()-1].MAC = fromAddress;
        dictionary[dictionary.size()-1].pin = inputPort;
    }
    
    //Step 3
    if(stoi(toAddress.substr(1,1)) % 2 != 0)
    {
        cout << "flood" << endl;
        return;
    }
    
    //Step 4
    for(int i = 0; i < dictionary.size(); i++)
        if(dictionary[i].MAC == toAddress)
        {
            Pout = dictionary[i].pin;
            break;
        }
    if(Pout < 0)
    {
        cout << "flood" << endl;
        return;
    }
    
    //Step 5
    if(Pout == inputPort)
    {
        cout << "drop" << endl;
        return;
    }
    
    //Step 6
    cout << Pout << endl;
}

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */ 
    int numIterations;
    cin >> numIterations;
    
    int inputPort;
    string fromAddress;
    string toAddress;
    
    for(int i = 0; i < numIterations; i++)
    {
        cin >> inputPort;
        cin >> toAddress;
        cin >> fromAddress;
        
        switchAlgorithm(inputPort, fromAddress, toAddress);
    }
    return 0;
}