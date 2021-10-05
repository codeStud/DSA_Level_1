#include<iostream>
#include<vector>

using namespace std;

// sr - source row
// sc - source column
// dr - destination row
// dc - destination column
vector <string> getMazePaths(int sr, int sc, int dr, int dc) {
    // base case
    if(sr > dr || sc > dc){
        // return an empty vector
        vector <string> res;
        return res;
    }
    
    if(sr == dr && sc == dc){
        vector <string> res;
        res.push_back("");
        return res;
    }
    
    vector <string> hPaths = getMazePaths(sr, sc + 1, dr, dc);
    vector <string> vPaths = getMazePaths(sr + 1, sc, dr, dc);
    
    // Declare another vector to store the final result
    vector <string> finalPaths;
    
    // Append "h" in front of hPaths
    for(string st : hPaths){
        finalPaths.push_back("h" + st);
    }
    
    //Append "v" in front of vPaths
    for(string st : vPaths){
        finalPaths.push_back("v" + st);
    }
    
    return finalPaths;

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
    vector<string> ans = getMazePaths(0,0,n-1,m-1);
    display(ans);

    return 0;
}