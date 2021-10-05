#include<iostream>
#include<vector>
using namespace std;

int saddlePoint(vector<vector<int>>& arr, int n)
{
    for(int i = 0; i < n; i++){
        
        // let first element be the smallest
        int smallest = 0;
        
        // find column of smallest in the row
        for(int j = 1; j < n; j++){
            if(arr[i][j] < arr[i][smallest]){
                smallest = j;
            }
        }
        
        // let's assume the current element is the saddle point
        int flag = 1;
        
        // find if this smallest in row element, is max in the column
        for(int k = 0; k < n; k++){
            if(arr[k][smallest] > arr[i][smallest]){
                flag = 0;
                break;
            }
        }
        
        if(flag != 0){
            return arr[i][smallest];
        }
    }
    
    // saddle point not found
    return 0;
}

int main()
{
    int n;
    cin>>n;
    
    vector<vector<int>> arr (n, vector<int> (n));
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cin>>arr[i][j];
        }
    }
    
    int res = saddlePoint(arr, n);
    
    if(!res){
        cout<<"Invalid input"<<endl;
    }
    else{
        cout<<res<<endl;
    }
    
    return 0;
}