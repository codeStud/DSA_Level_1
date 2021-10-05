#include<iostream>
using namespace std;

int anyBaseToDecimal(int num, int base)
{
    int ans = 0;
    int power = 1;
    int rem = 0;
    
    while(num > 0){
        // since converting to decimal, divide and get remainder by 10
        rem = num % 10;
        num = num / 10;
        
        // keep adding the rem after multiplying it with the power of given base
        ans += rem * power;
        
        // keep incrementing power in multiples of the given base
        power = power * base;
    }
    
    return ans;
}

int main()
{
    int num, base;
    cin>>num>>base;
    
    cout<<anyBaseToDecimal(num, base);
    
    return 0;
}