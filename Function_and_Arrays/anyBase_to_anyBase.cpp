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

int anyBaseToAnyBase(int num, int sourceBase, int targetBase)
{
    // convert source base to decimal
    int decimalVal = anyBaseToDecimal(num, sourceBase);
    
    // convert decimal to target base
    int targetNum = decimalToAnyBase(decimalVal, targetBase);
    
    return targetNum;
}

int main()
{
    int num, sourceBase, targetBase;
    cin>>num>>sourceBase>>targetBase;
    
    cout<<anyBaseToAnyBase(num, sourceBase, targetBase);
    
    return 0;
}