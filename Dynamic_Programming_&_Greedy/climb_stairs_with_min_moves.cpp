#include<iostream>
#include<vector>
#include<climits>
using namespace std;

void minMoves(int *arr, int n)
{
    vector <int> memo (n+1, INT_MAX);
    
    // 0 moves to go from n to n
    memo[n] = 0;
    
    for(int i = n-1; i >= 0; i--){
        int minVal = INT_MAX;
        if(arr[i] != 0){
            for(int j = 1; j <= arr[i] && i + j <= n; j++){
                if(memo[i + j] != INT_MAX)
                    minVal = min(minVal, memo[i + j]);
            } 
        }
        
        if(minVal != INT_MAX){
            memo[i] = 1 + minVal;
        }
    }
    
    if(memo[0] != INT_MAX){
        cout<<memo[0]<<endl;
    }
    else{
        cout<<"null"<<endl;
    }
}

int main(){
    int n;
    cin>>n;
    int arr[n];
    for(int i = 0 ; i < n ;i++){
        cin>>arr[i];
    }
    
    minMoves(arr,n);
}