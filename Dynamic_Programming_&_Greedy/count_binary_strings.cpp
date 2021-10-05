#include<iostream>
using namespace std;

int main()
{
    int n;
    cin>>n;
    
    int prevEnding0 = 1;    // 1 binary string possible of length=1 ending with 0
    int prevEnding1 = 1;    // 1 binary string possible of length=1 ending with 1
    
    // making binary strings of length 2 to n by adding 1 or 0 to the previous strings following the rule
    for(int i = 2; i <= n; i++){
        // can add another 1 behind the prevEnding0 & prevEnding1 strings as it won't result in 2 consecutive zeros
        int newEnding1 = prevEnding0 + prevEnding1;
        
        // can add another 0 behind only prevEnding1 strings as adding a 0 behind prevEnding0 strings will result in 2 consecutive zeros
        int newEnding0 = prevEnding1;
        
        // Now move prevEnding0 & prevEnding1 variable forward
        prevEnding0 = newEnding0;
        prevEnding1 = newEnding1;
    
    }
    
    cout<< prevEnding0 + prevEnding1;
    
    return 0;
}