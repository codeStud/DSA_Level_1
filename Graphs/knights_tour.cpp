#include<iostream>
#include<vector>
using namespace std;

void display(vector<vector<int>>& chess){
    for(int i = 0; i < chess.size(); i++){
        for(int j = 0; j < chess[0].size(); j++){
            cout<<chess[i][j]<<" ";
        }
        cout<<endl;
    }
    cout<<endl;
}

void knightsTour(vector<vector<int>>& chess, int r, int c, int move)
{
    // base case
    if(r < 0 || c < 0 || r >= chess.size() || c >= chess.size() || chess[r][c] != 0){
        return;
    }
    
    if(move == chess.size() * chess.size()){
        // place the current move on chess-board
        chess[r][c] = move;
        
        display(chess);
        // remove the move
        chess[r][c] = 0;
        return;
    }
    
    // enter move number in current cell
    chess[r][c] = move;
    
    // make calls
    knightsTour(chess, r-2, c+1, move+1);
    knightsTour(chess, r-1, c+2, move+1);
    knightsTour(chess, r+1, c+2, move+1);
    knightsTour(chess, r+2, c+1, move+1);
    knightsTour(chess, r+2, c-1, move+1);
    knightsTour(chess, r+1, c-2, move+1);
    knightsTour(chess, r-1, c-2, move+1);
    knightsTour(chess, r-2, c-1, move+1);
    
    // remove the moves on return
    chess[r][c] = 0;
    
}

int main()
{
    int n, row, col;
    cin>>n>>row>>col;
    
    vector<vector<int>> chess(n, vector<int>(n));
    
    // pass chess-board, starting row, col & move number
    knightsTour(chess, row, col, 1);
}