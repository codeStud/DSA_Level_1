#include<iostream>
using namespace std;

int main()
{
    int n;
    cin>>n;
    
    int wt[n], val[n];
    
    // Take value first
    for(int i = 0; i < n; i++){
        cin>>val[i];
    }
    
    // Then take weights
    for(int i = 0; i < n; i++){
        cin>>wt[i];
    }
    
    int cap;
    cin>>cap;
    
    // Since repeatation is allowed => 1-D array for storing the result
    int dp[cap+1] = {0};
    
    for(int i = 1; i <= cap; i++){
        int maxProfit = 0;
        for(int j = 0; j < n; j++){
            // include the item only if capacity of knapsack is greater/equal than the weight of item 
            // also, insert the max profit obtained by checking which single item should be included
            // for the current capacity 'i', in order to get max-profit.
            if(wt[j] <= i){
                int profit = val[j] + dp[i-wt[j]];
                if(profit > maxProfit){
                    maxProfit = profit;
                }
            }
        }
        dp[i] = maxProfit;
    }
    
    cout<<dp[cap];
    
    return 0;
}