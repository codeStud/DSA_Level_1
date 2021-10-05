#include<iostream>
#include<vector>
using namespace std;


void exitPoint(vector <vector<int>> arr, int n, int m)
{
    // dir = 0 => moving east
    // dir = 1 => moving south
    // dir = 2 => moving west
    // dir = 3 => moving north
    
    int dir = 0;    // initially North
    
    int i = 0; // current row
    int j = 0; // current col
    
    while(true){
        // determine the current moving direction
        dir = (dir + arr[i][j]) % 4;
        
        if(dir == 0){
            // move east
            j++;
        }
        else if(dir == 1){
            // move south
            i++;
        }
        else if(dir == 2){
            // move west
            j--;
        }
        else{
            // move north
            i--;
        }
        
        // check if you've come out of the maze
        if(i < 0){
            // increment i to print the last arr cell
            i++;
            break;
        }
        else if(j < 0){
            // increment j to print the last arr cell
            j++;
            break;
        }
        else if(i == n){
            // decrement i to print the last arr cell
            i--;
            break;
        }
        else if(j == m){
            // decrement j to print the last arr cell
            j--;
            break;
        }
        else{
            // nothing
        }
    }
    
    // print the exit point
    cout<<i<<endl<<j<<endl;
}


int main()
{
    int n, m;
    cin>>n>>m;
    
    vector <vector<int>> arr(n, vector<int> (m));
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cin>>arr[i][j];
        }
    }
    
    exitPoint(arr, n, m);
    
    return 0;
}