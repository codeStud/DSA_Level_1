#include<iostream>
using namespace std;

int main()
{
    int n;
    cin>>n;
    
    int arr[n];
    for(int i = 0; i < n; i++){
        cin>>arr[i];
    }
    
    // sum after including the element.
    int incSum = arr[0];
    
    // sum after excluding the element
    int excSum = 0;
    
    for(int i = 1; i < n; i++){
        // to avoid including two adjacent array elements, can include only if prev element was excluded
        int newIncSum = arr[i] + excSum;
        
        // for exluding current element, we can either take prev element inclusion or prev element exclusion 
        // as in both cases, no two array elements would be adjacent. But take the max of those 2 (GREEDY)
        int newExcSum = max(incSum, excSum);
        
        // move the incSum and excSum ahead to point till the sum of current elements
        incSum = newIncSum;
        excSum = newExcSum;
    }
    
    // max of incSum and excSum at the end will give you the maxSum
    cout<<max(incSum, excSum);
    
    return 0;
}