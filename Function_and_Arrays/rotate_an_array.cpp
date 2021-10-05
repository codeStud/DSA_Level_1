#include<iostream>
using namespace std;

void reverse(int* arr, int start, int end)
{
    for(int i = start, j = end; i < j; i++, j--){
       int temp = arr[i];
       arr[i] = arr[j];
       arr[j] = temp;
   }
}

void rotate(int* arr, int n, int k){
    // you'll get the original array in below cases
   if(k == 0 || k % n == 0){
       return;
   }
   
   // if k > n then find how many times we need to rotate
   k = k % n;
   
   // if k is negative, it will give same output as that of n + k
   if(k < 0){
       k = k + n;
   }
   
   reverse(arr, 0, n-k-1);
   reverse(arr, n-k, n-1);
   reverse(arr, 0, n-1);
    
}

void display(int* arr, int n){
    for(int i = 0 ; i < n; i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}

int main(){
    int n, r;
    cin>>n;
    int* arr = new int[n];
    for(int i = 0 ; i < n; i++){
        cin>>arr[i];
    }
    cin>>r;
    
    rotate(arr,n,r);
    display(arr,n);
}