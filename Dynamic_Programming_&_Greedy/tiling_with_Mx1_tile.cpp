#include<iostream>
using namespace std;

int main()
{
    int n, m;
    cin>>n>>m;
    
    // Two choice for placing each m*1 tile:
    // Choice 1: Vertically => 0 width remaining + n-1 length remaining
    // Choice 2: Horizontally => m-1 width remaining + n-m length remaining
    
    int dp[n+1]; // index of dp represents the length of the floor
    
    for(int i = 1; i <= n; i++){
        //Base case 1: If length is less than width 'm' of tile => Can place all the tiles ONLY VERTICALLY
        if(i < m){
            dp[i] = 1;
        }
        
        //Base case 2: If length of floor == width 'm' of tile => Can place all tiles either horizontally or all vertically
        else if(i == m){
            dp[i] = 2;
        }
        
        // otherwise, no. of ways to fill floor of 'i' length = (no. of ways to fill n-1 length i.e m*1 tile is placed vertically) + (no. of ways to fill n-m length i.e m*1 tile is placed horizontally)
        
        // If horizontally placed, the m-1 remaining WIDTH can be filled only in ONE way, i.e all the tiles placed horizontally
        else{
            dp[i] = dp[i-1] + dp[i-m];
        }
        
    }
    
    cout<<dp[n];
    
    return 0;
}