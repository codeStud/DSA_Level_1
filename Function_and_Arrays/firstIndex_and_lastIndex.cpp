#include<iostream>
using namespace std;

int main(){
    int n;
    cin>>n;
    int* arr = new int[n];
    for(int i = 0 ; i < n; i++){
        cin>>arr[i];
    }
    int data;
    cin>>data;
    
    // write your code here
    int lo = 0;
    int hi = n-1;
    int fi = -1;
    
    while(lo <= hi){
        int mid = lo + ((hi - lo) / 2);
        
        if(arr[mid] < data){
            lo = mid + 1;
        }
        else if(arr[mid] > data){
            hi = mid - 1;
        }
        else{
            fi = mid;
            // go left to see if anymore data exists
            hi = mid - 1;
        }
    }
    
    cout<<fi<<endl;
    
    lo = 0, hi = n-1;
    int li = -1;
    
    while(lo <= hi){
        int mid = lo + ((hi - lo) / 2);
        
        if(arr[mid] < data){
            lo = mid + 1;
        }
        else if(arr[mid] > data){
            hi = mid - 1;
        }
        else{
            li = mid;
            // go right to see if anymore data exists
            lo = mid + 1;
        }
    }
    
    cout<<li<<endl;
}