#include<iostream>
#include<queue>
using namespace std;

void sortKSorted(int *arr, int n, int k)
{
    // MIN Heap
    priority_queue <int, vector<int>, greater<int>> pq;
    
    // add first 0 to k elements in the pq
    for(int i = 0; i <= k; i++){
        pq.push(arr[i]);
    }
    
    //keep popping the elements (smaller to greater) and keep pushing the elements from k+1
    for(int i = k+1; i < n; i++){
        cout<<pq.top()<<endl;
        pq.pop();
        
        // Note that pq will always contain only k+1 elements
        pq.push(arr[i]);
    }
    
    // at last, pop all the remaining elements
    while(!pq.empty()){
        cout<<pq.top()<<endl;
        pq.pop();
    }
}


int main()
{
    int n;
    cin>>n;
    
    int arr[n];
    for(int i = 0; i < n; i++){
        cin>>arr[i];
    }
    
    int k;
    cin>>k;
    
    sortKSorted(arr, n, k);
    
    return 0;
}