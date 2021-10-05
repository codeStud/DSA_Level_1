#include<iostream>
#include<algorithm>
using namespace std;

int main()
{
    int n;
    cin>>n;
    
    int arr[n][3];
    for(int i = 0; i < n; i++){
        for(int j = 0; j < 3; j++){
            cin>>arr[i][j];
        }
    }
    
    long dp[n][3];
    // cost of painting 1st house red following the rule
    dp[0][0] = arr[0][0];
    
    // cost of painting the 1st house blue following the rule
    dp[0][1] = arr[0][1];
    
    // cost of painting the 1st house green following the rule
    dp[0][2] = arr[0][2];
    
    for(int i = 1; i < n; i++){
        // cost of painting the ith house red following the rule = cost of red paint for ith house + minimum(cost of painting prev house blue, cost of painting prev house green)
        dp[i][0] = arr[i][0] + min(dp[i-1][1], dp[i-1][2]);
        
        // cost of painting the ith house blue following the rule = cost of blue paint for ith house + minimum(cost of painting prev house red, cost of painting prev house green)
        dp[i][1] = arr[i][1] + min(dp[i-1][0], dp[i-1][2]);
        
        // cost of painting the ith house green following the rule = cost of green paint for ith house + minimum(cost of painting prev house red, cost of painting prev house blue)
        dp[i][2] = arr[i][2] + min(dp[i-1][0], dp[i-1][1]);
    }
    
    cout<<min({dp[n-1][0], dp[n-1][1], dp[n-1][2]});
    
    return 0;
}