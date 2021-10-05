#include<iostream>
using namespace std;

int decimalToAnyBase(int num, int base)
{
    int rem;
    int power = 1;
    int ans = 0;
    
    while(num > 0){
        // get the remainder
        rem = num % base;
        // change the num
        num = num / base;
        
        // keep storing rem by multiplying it with powers of 10
        ans += rem * power;
        
        // increase the power by mutiples of 10 to get the reverse of remainder effect
        power = power * 10;
    }
    
    return ans;
}

int main()
{
    int num, base;
    cin>>num>>base;
    
    cout<<decimalToAnyBase(num, base);
    
    return 0;
}