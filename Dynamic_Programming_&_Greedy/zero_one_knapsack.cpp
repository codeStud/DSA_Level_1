#include<iostream>
using namespace std;

int main()
{
    int n;
    cin>>n;
    int val[n], wt[n];
    
    for(int i = 0; i < n; i++){
        cin>>val[i];
    }
    
    for(int i = 0; i < n; i++){
        cin>>wt[i];
    }
    
    int capacity;
    cin>>capacity;
    
    int dp[n+1][capacity+1];
    
    for(int i = 0; i <= n; i++){
        for(int j = 0; j <= capacity; j++){
            dp[i][j] = 0;
        }
    }
    
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= capacity; j++){
            // if the item is heavier than the current capacity
            if(j < wt[i-1]){
                // don't include the item
                dp[i][j] = dp[i-1][j];
            }
            else{
                dp[i][j] = max(dp[i-1][j], val[i-1] + dp[i-1][j-wt[i-1]]);
            }
            
        }
    }
    
    cout<<dp[n][capacity];
    
    return 0;
}