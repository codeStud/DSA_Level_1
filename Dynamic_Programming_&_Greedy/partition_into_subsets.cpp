#include<iostream>
using namespace std;

// ````````````MEMOIZATION SOLUTION`````````````
// long solution(int n, int k, vector<vector<long>>& dp)
// {
//     if(n == 0 && k == 0){
//         dp[n][k] = 1;
//     }
//     else if(n == 0 || k == 0){
//         dp[n][k] = 0;
//     }
//     else if(dp[n][k] != -1){
//         return dp[n][k];
//     }
//     else{
//         // comment return dp[n][k] from above and uncomment cout below, in order to see
//         // the effect of memoization.
//         // cout<<n<<" "<<k<<endl;
//         dp[n][k] = k * solution(n-1, k, dp) + solution(n-1, k-1, dp);
//     }
    
//     return dp[n][k];
// }


int main()
{
    int n, k;
    cin>>n>>k;
    
    long dp[n+1][k+1];
    
    for(int i = 0; i <= n; i++){
        for(int j = 0; j <= k; j++){
            // 0 elements into 0 subset => 1 way = []
            if(i == 0 && j == 0){
                dp[i][j] = 1;
            }
            
            // 0 elements in j>1 subsets = 0 ways & i>1 elements into 0 subsets = 0 ways
            else if(i == 0 || j == 0){
                dp[i][j] = 0;
            }
            // case1: Make all the j subsets from i-1 elements. The ith element can come in pair with any of the j subsets. Thus, j * dp[i-1][j]
            
            // case2: Make j-1 subsets from i-1 elements. The ith element will make the jth subset by being alone. Thus, 1 * dp[i-1][j-1]
            
            else{
                dp[i][j] = j*dp[i-1][j] + dp[i-1][j-1];
            }
            
        }
    }
    
    cout<<dp[n][k];
    
    return 0;
}