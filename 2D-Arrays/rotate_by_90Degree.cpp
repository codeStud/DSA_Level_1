#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

void rotateBy90(vector<vector<int>>& arr, int n)
{
    // In order to rotate clockwise, first reverse the columns
        // 1 2 3        7 8 9
        // 4 5 6   ==>  4 5 6
        // 7 8 9        1 2 3
    reverse(arr.begin(), arr.end());
    
    // swap the diagonally opposite elements
    // loop through upper triangular or lower triangular matrix
    for(int i = 0; i < n; i++){
        for(int j = i; j < n; j++){
            swap(arr[i][j], arr[j][i]);
        }
    }
}

int main()
{
    int n;
    cin>>n;
    
    vector <vector<int>> arr (n, vector <int> (n));
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cin>>arr[i][j];
        }   
    }
    
    rotateBy90(arr, n);
    
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cout<<arr[i][j]<<" ";
        }
        cout<<endl;
    }
    
    return 0;
}