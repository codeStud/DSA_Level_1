#include<iostream>
using namespace std;

int main(){
    int n1, n2;
    cin>>n1;
    int* arr1 = new int[n1];
    for(int i = 0 ; i < n1; i++){
        cin>>arr1[i];
    }
    
    cin>>n2;
    int* arr2 = new int[n2];
    for(int i = 0 ; i < n2; i++){
        cin>>arr2[i];
    }
    
    // create an array of greater size amongst arr1 and arr2
    int* sum = new int[n1 > n2 ? n1 : n2];
    
    int i = n1 - 1;     // index of arr1
    int j = n2 - 1;     // index of arr2
    int k = max(n1, n2) - 1;        // index of sum array
    
    int sumSize = k;    // storing the size of sum array in a variable
    
    int carry = 0;
    while(k >= 0){
        int digit = carry;
        
        if(i >= 0){
            digit += arr1[i];
        }
        
        if(j >= 0){
            digit += arr2[j];
        }
        
        sum[k] = digit % 10;
        carry = digit / 10;
        
        i--;
        j--;
        k--;
    }
    
    if(carry > 0){
        cout<<carry<<endl;
    }
    
    for(int i = 0; i <= sumSize; i++){
        cout<<sum[i]<<endl;
    }
    
    return 0;
}