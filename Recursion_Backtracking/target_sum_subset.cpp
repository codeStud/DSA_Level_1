#include<iostream>
#include<string>
using namespace std;

int n;

void printTargetSumSubsets(int* arr, int idx, string subset, int sum, int target)
{
    // Base case
    
    if(sum > target)
        return;
        
    if(idx == n){
        if(sum == target){
            subset = subset + ".";
            cout<<subset<<endl;
        }
        return;
    }
    
    // Include the current index element in subset
    printTargetSumSubsets(arr, idx + 1, subset + to_string(arr[idx]) + ", ", sum + arr[idx], target);
    
    // Don't include the current index element in subset
    printTargetSumSubsets(arr, idx + 1, subset, sum, target);
}

int main()
{
    cin>>n;
    
    int arr[n];
    
    for(int i = 0; i < n; i++){
        cin>>arr[i];
    }
    
    int target;
    cin>>target;
    printTargetSumSubsets(arr, 0, "", 0, target);
}