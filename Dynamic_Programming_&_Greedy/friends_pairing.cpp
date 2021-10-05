// Watch this lecture with coin-change combination + coin change permutation + unbounded knapsack.
// Then you'll understand that -

//``````````PERMUTATION Generated````````````` 
// when you express all choices 
// - 1. for a particular iteration of the loop (current index of array: try all choices, next index of array: try all choices, so on...)
// - 2. for each level in euler diagram (level-1: all possible choices, level-2: all possible choices....)

//``````````COMBINATION Generated````````````` 
// when you express choices one after the another 
// - 1. for entire iteration of loop (for 1st choice iterates over the entire array, then 2nd choice iterates over the entire array, then 3rd ...) 
// - 2. for each level in euler (1st choice: level-1, 2nd choice: level-2...)

#include<iostream>
using namespace std;

int main()
{
    int n;
    cin>>n;
    
    int dp[n+1];
    
    // 1 kid can be paired up in 1 way, i.e alone
    dp[1] = 1;
    
    // 2 kids can be paired up in 2 ways, i.e both alone + both together
    dp[2] = 2;
    
    // dp[i-1] => ith kid decided to be single => deal with reamining i-1 kids. Thus, dp[i-1]
    // dp[i-2] => ith kid decided to pair up with another kid (i-1 choices for ith kid to pair up) => deal with reamining i-2 kids. Thus, (i-1)*dp[i-2]
    for(int i = 3; i <= n; i++){
        dp[i] = dp[i-1] + (i-1)*dp[i-2];
    }
    
    cout<<dp[n];
    
    return 0;
}