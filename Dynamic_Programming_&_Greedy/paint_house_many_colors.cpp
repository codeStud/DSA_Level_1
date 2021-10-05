#include<iostream>
#include<climits>
using namespace std;

int main()
{
    int n, c;
    cin>>n>>c;
    
    int arr[n][c];
    
    for(int i = 0; i < n; i++){
        for(int j = 0; j < c; j++){
            cin>>arr[i][j];
        }
    }
    
    int least = INT_MAX;
    int secondLeast = INT_MAX;
    
    int dp[n][c];
    for(int i = 0; i < n; i++){
        for(int j = 0; j < c; j++){
            dp[i][j] = 0;
        }
    }
    
    // filling out the first row and updating least & secondLeast
    for(int j = 0; j < c; j++){
        dp[0][j] = arr[0][j];
        
        if(dp[0][j] < least){
            secondLeast = least;        // previous least will become new secondLeast
            least = dp[0][j];      // arr[0][j] will become the new least
        }
        else if(dp[0][j] < secondLeast){
            secondLeast = dp[0][j];
        }
    }
    
    for(int i = 1; i < n; i++){
        int newLeast = INT_MAX;
        int newSecondLeast = INT_MAX;
        
        for(int j = 0; j < c; j++){
            // if least is same as the element above => take the secondLeast
            if(least == dp[i-1][j]){
                dp[i][j] = arr[i][j] + secondLeast;
            }
            else{
                dp[i][j] = arr[i][j] + least;
            }
            
            // Also, keep track of least and second least of the current row
            if(dp[i][j] < newLeast){
                newSecondLeast = newLeast;      // previous newLeast will become the secondLeast
                newLeast = dp[i][j];   // update the newLeast
            }
            else if(dp[i][j] < newSecondLeast){
                // only update the second least value in the current row
                newSecondLeast = dp[i][j];
            }
            
        }
        
        // move the least and secondLeast to the ith row
        least = newLeast;
        secondLeast = newSecondLeast;
    }
    
    // least in the last row will be the minimum cost to paint all houses following the rules 
    cout<<least;
    
    return 0;
}