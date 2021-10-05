#include<iostream>
using namespace std;

int coinChangeCombinations(int *arr, int n, int sum)
{
    int dp[sum+1] = {0};
    dp[0] = 1;
    
    // iterate over coins array in the outer loop to produce combination and NOT permutation
    for(int i = 0; i < n; i++){
        for(int j = 1; j <= sum; j++){
            
            // if the sum is greater than or equal to the current coin denomination
            if(j >= arr[i]){
                dp[j] += dp[j - arr[i]];        
            }
            
        }
    }
    return dp[sum];
}

int main()
{
    int n;
    cin>>n;
    int coins[n];
    
    for(int i = 0; i < n; i++){
        cin>>coins[i];
    }
    
    int sum;
    cin>>sum;
    
    cout<<coinChangeCombinations(coins, n, sum);
}