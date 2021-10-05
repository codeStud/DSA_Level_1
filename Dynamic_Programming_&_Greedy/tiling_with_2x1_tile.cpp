#include<iostream>
using namespace std;

int main()
{
    int n;
    cin>>n;
    
    // Now, for every 2*1 tile, we have two choices - CHOICE:1) Place it vertically => 2cm width covered + n-1 length remaining.  CHOICE:2) Place it horizontally => 1cm width remaining + n-2 length remaining
    
    int dp[n+1]; // index of dp reprents the length of the floor
    
    // Base cases
    dp[1] = 1;  // 1 way to place 2*1 tile in 2*1 floor = vertically
    dp[2] = 2; // 2 ways to place 2*1 tile on 2*2 floor = (both horizontally) + (both vertically)
    
    // for length 3 to n
    for(int i = 3; i <= n; i++){
        // for choice1: no. of ways to fill the floor = no. of ways to fill remaining (n-1) length
        // for choice2: no. of ways to fill floor = no. of ways to fill remaining (n-2) length * 1 (bcz 1cm remaining width can be filled only by placing 1 tile horizontally => 1 choice)
        
        dp[i] = dp[i-1] + dp[i-2];
    }
    
    cout<<dp[n];
    
    return 0;
}