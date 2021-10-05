#include <iostream>
#include<vector>
using namespace std;

// int cs(int arr[], int n){
//     int cache[n+1] = {0};
//     cache[n] = 1;
    
//     for(int i = n-1; i >= 0; i--){
//         for(int j = 1; j <= arr[i] && i + j <= n; j++){
//             cache[i] += cache[i+j];
//         }
//     }
    
//     return cache[0];
// }

int cs_top_down(vector<int>& arr, int i, vector<int>& dp)
{
    if(i == arr.size()){
        return 1;
    }
    
    if(i > arr.size()){
        return 0;
    }
    
    if(dp[i] > 0){
        return dp[i];
    }
    
    for(int j = 1; j <= arr[i]; j++){
        int count = cs_top_down(arr, i + j, dp);
        dp[i] += count;
    }
    
    return dp[i];
}


int main(){
    int n;
    cin>>n;
    vector <int> arr(n);
    for(int i = 0 ; i < n ;i++){
        cin>>arr[i];
    }
    // cout<<cs(arr,n)<<endl;
    
    vector <int> dp(n+1, 0);
    cout<<cs_top_down(arr, 0, dp);
    
    return 0;
}