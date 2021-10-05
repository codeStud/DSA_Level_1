#include<iostream>
#include<queue>
using namespace std;

void kLargestElement(int *arr, int n, int k)
{
    // MIN Heap
    priority_queue <int, vector<int>, greater<int>> pq;
    
    for(int i = 0; i < n; i++){
        // add only k elements to the pq. This way pq will have only k elements in it with minimum element on top
        if(i < k){
            pq.push(arr[i]);
        }
        else{
            // keep pushing the greater elements
            if(arr[i] > pq.top()){
                // pop the least element (Min Heap)
                pq.pop();
                
                // push the greater element
                pq.push(arr[i]);
            }
        }
    }
    
    // pq willl have greatest k elements, with smallest at the root
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
    
    kLargestElement(arr, n, k);
    
    return 0;
}