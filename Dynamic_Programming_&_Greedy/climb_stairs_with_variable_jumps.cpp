#include <iostream>
using namespace std;

int cs(int arr[], int n){
    int cache[n+1] = {0};
    cache[n] = 1;
    
    for(int i = n-1; i >= 0; i--){
        for(int j = 1; j <= arr[i] && i + j <= n; j++){
            cache[i] += cache[i+j];
        }
    }
    
    return cache[0];
}

int main(){
    int n;
    cin>>n;
    int arr[n];
    for(int i = 0 ; i < n; i++){
        cin>>arr[i];
    }
    cout<<cs(arr,n)<<endl;
}   