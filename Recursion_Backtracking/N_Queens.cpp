#include<iostream>
#include<vector>
#include<string>
using namespace std;

int n;

bool isSafeMove(vector<vector<int>>& chess, int row, int col)
{
    // check if queen in above row & in the same column
    for(int i = row - 1; i >= 0; i--){
        if(chess[i][col] == 1){
            return false;
        }
    }
    
    // check if queen in top left diagonal
    for(int i = row-1, j = col-1; i >= 0 && j >= 0; i--, j--){
        if(chess[i][j] == 1){
            return false;
        }
    }
    
    // check if queen in top right diagonal
    for(int i = row-1, j = col+1; i >= 0 && j < n; i--, j++){
        if(chess[i][j] == 1){
            return false;
        }
    }
    
    return true;
}


// Backtracking is required here because even if you pass chess by "value" after marking 1, 
// when the recursion folds back and come back again to the current stage - there is still a queen in 
// current row (which was set above the recursive call). So, when you continue with the next iteration of for loop, 
// you won't be able to place the queen in any column bcz you didn't remove the queen you placed in chess[row][col] before the recursive call.

void NQueens(vector<vector<int>>& chess, int row, string res)
{
    if(row == n){
        // print the current positions of the queens
        cout<<res<<"."<<endl;
        return;
    }
    
    for(int col = 0; col < n; col++){
        if(isSafeMove(chess, row, col)){
            // place the queen in current row and col
            chess[row][col] = 1;
            
            // make a call for the next row and append the current row+col to the res
            NQueens(chess, row+1, res + to_string(row) + "-" + to_string(col) + ", ");
            
            // remove the queen from the current row and col
            chess[row][col] = 0;
        }
    }
    
}

int main()
{
    cin>>n;
    
    vector <vector<int>> chess (n, vector<int> (n));
    
    NQueens(chess, 0, "");
    
    return 0;
}