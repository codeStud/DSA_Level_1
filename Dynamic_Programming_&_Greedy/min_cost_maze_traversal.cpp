#include<iostream>
#include<vector>
using namespace std;

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
    
    cout<<minCostMazePath(arr, n, m);
    
    return 0;
}