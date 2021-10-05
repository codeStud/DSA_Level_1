#include<iostream>
#include<vector>
using namespace std;

void find(vector<vector<int>>& arr, int n, int key)
{
    // start from the top right corner
    int row = 0, col = n-1;
    
    while(row < n && col >= 0){
        
        // if key is larger, go down
        if(arr[row][col] < key){
            row += 1;
        }
        
        // if key is smaller, go left
        else if(arr[row][col] > key){
            col -= 1;
        }
        
        // found
        else{
            cout<<row<<endl<<col<<endl;
            return;
        }
    }
    
    // not found
    cout<<"Not Found"<<endl;
}

int main()
{
    int n, key;
    cin>>n;
    
    vector<vector<int>> arr (n, vector<int> (n));
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cin>>arr[i][j];
        }
    }
    
    cin>>key;
    
    find(arr, n, key);
    
    return 0;
}