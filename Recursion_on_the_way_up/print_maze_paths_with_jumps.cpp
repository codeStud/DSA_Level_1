#include<iostream>
#include<string>
using namespace std;


void printMazePaths(int sr, int sc, int dr, int dc, string psf) {
    // Base case
    if(sr == dr && sc == dc){
        cout<<psf<<endl;
        return;
    }
    
    // Horizontal Moves
    for(int moveSize = 1; moveSize <= dc - sc; moveSize++){
        printMazePaths(sr, sc + moveSize, dr, dc, psf + "h" + to_string(moveSize));
    }
    
    // Vertical Moves
    for(int moveSize = 1; moveSize <= dr - sr; moveSize++){
        printMazePaths(sr + moveSize, sc, dr, dc, psf + "v" + to_string(moveSize));
    }
    
    // Diagonal Moves
    for(int moveSize = 1; moveSize <= dc - sc && moveSize <= dr - sr; moveSize++){
        printMazePaths(sr + moveSize, sc + moveSize, dr, dc, psf + "d" + to_string(moveSize));
    }
    
}

int main() {
    int n ;
    int m ;cin>>n>>m;
    printMazePaths(0, 0, n - 1, m - 1, "");
}