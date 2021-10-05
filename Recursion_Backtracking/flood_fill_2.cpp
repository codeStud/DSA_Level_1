#include<iostream>
#include<vector>
using namespace std;

// Backtracking required here as visited is passed by "reference" => only a single copy of visited is there. So, when recursion folds back, the updated values will still be there and we'll have to reset it back to 0 explicitly.
/*
void floodfill(vector<vector<int>> maze, int row, int col, string ans, vector<vector<int>>& visited) {
    
    // base case
    if(row < 0 || col < 0 || row == maze.size() || col == maze[0].size() || 
        maze[row][col] == 1 || visited[row][col] == 1){
            
            return;
            
        }
        
    if(row == maze.size() - 1 && col == maze[0].size() - 1){
        cout<<ans<<endl;
        return;
    }
    
    visited[row][col] = 1;
    
    floodfill(maze, row - 1, col, ans + 't', visited);
    floodfill(maze, row, col - 1, ans + 'l', visited);
    floodfill(maze, row + 1, col, ans + 'd', visited);
    floodfill(maze, row, col + 1, ans + 'r', visited);

    visited[row][col] = 0;
}
*/

// NO BACKTRACKING required as visited is passed by "value" => for every recursive call, a new copy of visited is made & previously modified values will be reflected in this copy. But, when recursion folds back, the visited copy of previous call will be removed from "stack" and the current copy of visited will be used, i.e state of visited is automatically re-stored when recursion folds back.

void floodfill(vector<vector<int>> maze, int row, int col, string ans, vector<vector<int>> visited) {
    
    // base case
    if(row < 0 || col < 0 || row == maze.size() || col == maze[0].size() || 
        maze[row][col] == 1 || visited[row][col] == 1){
            
            return;
            
        }
        
    if(row == maze.size() - 1 && col == maze[0].size() - 1){
        cout<<ans<<endl;
        return;
    }
    
    visited[row][col] = 1;
    
    floodfill(maze, row - 1, col, ans + 't', visited);
    floodfill(maze, row, col - 1, ans + 'l', visited);
    floodfill(maze, row + 1, col, ans + 'd', visited);
    floodfill(maze, row, col + 1, ans + 'r', visited);

    // visited[row][col] = 0;
}

int main() {
    int n, m;
    cin >> n >> m;
    vector < vector < int >> arr(n, vector < int > (m));
    vector < vector < int >> visited(n, vector < int > (m));

    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++){
            cin >> arr[i][j];
            visited[i][j] = 0;
        }

    floodfill(arr, 0, 0, "", visited);
}