#include<iostream>
using namespace std;

bool targetSumSubset(int *arr, int n, int target)
{
    bool dp[n+1][target+1];
    
    for(int i = 0; i <= n; i++){
        for(int j = 0; j <= target; j++){
            
            if(i == 0 && j == 0){
                dp[i][j] = true;
            }
            else if(i == 0){
                dp[i][j] = false;
            }
            else if(j == 0){
                dp[i][j] = true;
            }
            else{
                if(j < arr[i-1]){
                    dp[i][j] = dp[i-1][j];
                }
                else{
                    dp[i][j] = (dp[i-1][j] || dp[i-1][j-arr[i-1]]);
                }
            }
            
        }
    }
    return dp[n][target];
}

int main()
{
    int n;
    cin>>n;
    
    int arr[n];
    for(int i = 0; i < n; i++){
        cin>>arr[i];
    }
    
    int target;
    cin>>target;
    
    if(targetSumSubset(arr, n, target)){
        cout<<"true";
    }
    else{
        cout<<"false";
    }
    
    return 0;
}