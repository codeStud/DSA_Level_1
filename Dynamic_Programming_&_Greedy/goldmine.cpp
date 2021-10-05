#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

int goldmine_bottom_up(vector<vector<int>> arr, int row, int col)
{
    int dp[row][col];
    
    // start travelling from rightmost column, down to 0th column
    for(int j = col-1; j >= 0; j--){
        for(int i = 0; i <= row-1; i++){
            
            // Divide the entire array into 4 parts -> rightmost column, topmost row, bottom-most row and rest of the cells
            
            // rightmost col => same value as of cell in arr
            if(j == col-1){
                dp[i][j] = arr[i][j];
            }
            
            // bottom-most row => can go horizontally forward or diagonally upward
            else if(i == row-1){
                dp[i][j] = arr[i][j] + max(dp[i][j+1], dp[i-1][j+1]);
            }
            
            // topmost row => can go horizontally forward or diagonally downward
            else if(i == 0){
                dp[i][j] = arr[i][j] + max(dp[i][j+1], dp[i+1][j+1]);
            }
            
            // for rest of the cells, we can go horizontally right, diagonally up & diagonally down
            else{
                dp[i][j] = arr[i][j] + max({dp[i][j+1], dp[i-1][j+1], dp[i+1][j+1]});
            } 
        }
    }
    
    // traverse the first column and then return the max of the first column
    int maxProfit = dp[0][0];
    for(int i = 1; i <= row-1; i++)
    {
        maxProfit = max(dp[i][0], maxProfit);
    }
    
    return maxProfit;
}


/*
int goldmine_top_down(vector<vector<int>>& arr, int row, int col, int n, int m, vector<vector<int>>& dp)
{
    if(row == n || col == m || row < 0){
        return 0;
    }
    
    if(col == m-1){
        dp[row][col] = arr[row][col];
        return dp[row][col];
    }
    
    if(dp[row][col] != 0){
        return dp[row][col];
    }
    
    
    for(int i = 0; i < n; i++){
        dp[i][col] = arr[i][col] + max({goldmine_top_down(arr, i-1, col+1, n, m, dp), 
                                goldmine_top_down(arr, i, col+1, n, m, dp),
                                goldmine_top_down(arr, i+1, col+1, n, m, dp)});
    }
    
    
    return dp[row][col];
}
*/

int main()
{
    int n, m;
    cin>>n>>m;
    vector<vector<int>> arr(n, vector<int>(m));

    vector<vector<int>> dp(n, vector<int>(m));
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cin>>arr[i][j];
        }
    }
   
    cout<<goldmine_bottom_up(arr, n, m);

    // vector<vector<int>> dp(n, vector<int>(m));
    // for(int i = 0; i < n; i++){
    //     for(int j = 0; j < m; j++){
    //         dp[i][j] = 0;
    //     }
    // }

    // goldmine_top_down(arr, 0, 0, n, m, dp);
    
    // int maxVal = -1;
    // for(int i = 0; i < n; i++){
    //     maxVal = max(dp[i][0], maxVal);    
    // }
    
    // cout<<maxVal;
    
    return 0;
}