#include<iostream>
#include<vector>
#include<string>

using namespace std;

// sr - source row
// sc - source column
// dr - destination row
// dc - destination column
vector <string> getMazePathsJumps(int sr, int sc, int dr, int dc) {
    // Base case
    if(sr == dr && sc == dc){
        vector <string> res;
        res.push_back("");
        return res;
    }
    
    // declare an array to store the final result
    vector <string> res;
    
    // Make horizontal jumps within the range of valid jump sizes and then append 'h1' or 'h2' or 'h3'... 'h moveSize' accordingly
    
    for(int moveSize = 1; moveSize <= dc - sc; moveSize += 1){
        vector <string> hPaths = getMazePathsJumps(sr, sc + moveSize, dr, dc);
        for(string hp : hPaths)
            res.push_back('h' + to_string(moveSize) + hp);
    }
    
    // Similarly for vertical jumps
    for(int moveSize = 1; moveSize <= dr - sr; moveSize += 1){
        vector <string> vPaths = getMazePathsJumps(sr + moveSize, sc, dr, dc);
        for(string vp : vPaths)
            res.push_back('v' + to_string(moveSize) + vp);
    }
    
    // Similarly for diagonal moves
    for(int moveSize = 1; moveSize <= dr - sr && moveSize <= dc - sc; moveSize += 1){
        vector <string> dPaths = getMazePathsJumps(sr + moveSize, sc + moveSize, dr, dc);
        for(string dp : dPaths)
            res.push_back('d' + to_string(moveSize) + dp);
    }
    
    return res;
}

void display(vector<string>& arr){
    cout << "[";
    for(int i = 0;i < arr.size();i++){
        cout << arr[i];
        if(i < arr.size() -1) cout << ", ";
    }
    
    cout << "]"<<endl;
}


int main() {
    int n,m; cin >> n >> m;
    vector<string> ans = getMazePathsJumps(0,0,n-1,m-1);
    display(ans);

    return 0;
}