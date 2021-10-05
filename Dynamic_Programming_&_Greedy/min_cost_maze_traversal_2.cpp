#include<iostream>
#include<vector>
#include<climits>
using namespace std;

/*
int minCostMazePath(vector<vector<int>> arr, int row, int col)
{
    // declare a dp array of same size as that of arr
    int dp[row][col];
    
    // traverse arr from bottom right to top left
    for(int i = row-1; i >= 0; i--){
        for(int j = col-1; j >= 0; j--){
            
            // Divide the entire arr region into 4 parts -> destination cell, bottom-most cell, rightmost-cells and rest of the cells.
            
            // if destination cell => cost will be same as the cost of dest in arr
            if(i == row-1 && j == col-1){
                dp[i][j] = arr[i][j];
                
            }
            
            // if bottom-most cells, then we can only go horizontally
            else if(i == row-1){
                dp[i][j] = arr[i][j] + dp[i][j+1];
                
            }
            
            // if rightmost cells, then we can only go vertically down
            else if(j == col-1){
                dp[i][j] = arr[i][j] + dp[i+1][j];
            }
            
            // for rest of the cells, we can either go horizontally or vertically
            else{
                dp[i][j] = arr[i][j] + min(dp[i+1][j], dp[i][j+1]);
            }
            
        }
    }
 
    
    return dp[0][0];
}
*/



// `````````````Top-Down Recursive Memoization Solution`````````````````

int minCostMazePath(vector<vector<int>> arr, int row, int col, int destR, int destC, vector<vector<int>>& dp)
{
    if(row == destR && col == destC){
        // if you return arr[row][col] here, it'll still give the correct answer.
        // However, you are returning directly without setting the value in dp[destR][destC]. So, dp[destR][destC] remains INT_MAX but all the other cells of dp would be filled appropriately.
        
        // Thus, just set dp[destR][destC] here and it'll anyways return by the below if condition
        dp[row][col] = arr[row][col];
    }
    
    if(dp[row][col] != INT_MAX){
        return dp[row][col];
    }
    
    if(row == destR){
        dp[row][col] = arr[row][col] + minCostMazePath(arr, row, col + 1, destR, destC, dp);
    }
    
    else if(col == destC){
        dp[row][col] = arr[row][col] + minCostMazePath(arr, row + 1, col, destR, destC, dp);
    }
    
    else{
        dp[row][col] = arr[row][col] + min( minCostMazePath(arr, row, col + 1, destR, destC, dp), minCostMazePath(arr, row + 1, col, destR, destC, dp) );
    }
    
    return dp[row][col];
}


int main()
{
    int n, m;
    cin>>n>>m;
    vector<vector<int>> arr(n, vector<int> (m));
    
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cin>>arr[i][j];
        }
    }
    
    // cout<<minCostMazePath(arr, n, m)<<endl;
    
    
    vector<vector<int>> dp(n, vector<int> (m));
    
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            dp[i][j] = INT_MAX;
        }
    }
    
    cout<<minCostMazePath(arr, 0, 0, n - 1, m - 1, dp)<<endl;
    
    // for(int i = 0; i < n; i++){
    //     for(int j = 0; j < m; j++){
    //         cout<<dp[i][j]<<" ";
    //     }
    //     cout<<endl;
    // }
    
    return 0;
}