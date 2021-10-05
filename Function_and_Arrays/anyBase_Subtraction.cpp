#include<iostream>
using namespace std;

int decimalToAnyBase(int num, int base)
{
    int rem = 0;
    int res = 0;
    int power = 1;
    
    while(num > 0){
        rem = num % base;
        num = num / base;
        
        res += rem * power;
        
        power = power * 10;
    }
    
    return res;
}

int anyBaseToDecimal(int num, int base)
{
    int rem = 0;
    int res = 0;
    int power = 1;
    
    while(num > 0){
        rem = num % 10;
        num = num / 10;
        
        res += rem * power;
        
        power = power * base;
    }
    
    return res;
}

int diffOfAnyBase(int base, int num1, int num2)
{
    int diff = 0;
    
    // convert both numbers into decimal
    int deci1 = anyBaseToDecimal(num1, base);
    int deci2 = anyBaseToDecimal(num2, base);
    
    // take the difference
    diff = deci2 - deci1;
    
    // convert diff to the given base
    int diffInGivenBase = decimalToAnyBase(diff, base);
    
    return diffInGivenBase;
}

int main()
{
    int base, num1, num2;
    cin>>base>>num1>>num2;
    
    cout<<diffOfAnyBase(base, num1, num2);
    
    return 0;
}