#include<iostream>
using namespace std;

int coinPermutation(int *coins, int n, int amount)
{
    int dp[amount+1] = {0};
    dp[0] = 1;
    
    for(int amt = 1; amt <= amount; amt++){
        for(int j = 0; j < n; j++){
            if(coins[j] <= amt){
                dp[amt] += dp[amt - coins[j]];
            }
        }
    }
    
    return dp[amount];
}


int main()
{
    int n, amount;
    cin>>n;
    int coins[n];
    
    for(int i = 0; i < n; i++){
        cin>>coins[i];
    }
    
    cin>>amount;
    
    cout<<coinPermutation(coins, n, amount);
    
    return 0;
}