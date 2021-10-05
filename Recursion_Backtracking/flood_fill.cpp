#include<iostream>
#include<vector>
using namespace std;

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

    visited[row][col] = 0;
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