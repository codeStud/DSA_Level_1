#include<iostream>
#include<stack>
using namespace std;

void findNextGreaterElement(int *arr, int n, int *nextGreaterElement)
{
    stack <int> st;
    
    // store index 'n' for last element
    nextGreaterElement[n-1] = n;
    // push the last index in the stack
    st.push(n-1);
    
    for(int i = n-2; i >= 0; i--){
        // we are pushing index in stack. So, compare with arr[st.top()] 
        while(!st.empty() && arr[i] >= arr[st.top()]){
            st.pop();
        }
        if(st.empty()){
            // Don't put -1 otherwise you won't be able to check if this next greater element is within the window 'k' or not. (Inside main())
            nextGreaterElement[i] = n;
        }
        else{
            nextGreaterElement[i] = st.top();
        }
        
        // push the INDEX of the current element on top
        st.push(i);
    }
    
}

int main()
{
    int n, k;
    cin>>n;
    
    int arr[n];
    for(int i = 0; i < n; i++){
        cin>>arr[i];
    }
    
    cin>>k;
    
    int nextGreaterElement[n];
    
    findNextGreaterElement(arr, n, nextGreaterElement);
    
    // loop until window contains the last element of the array
    for(int i = 0; i <= n-k; i++){
        // take another variable which eventually will point to the largest element in the window
        int j = i;
        
        // NOTE: j won't take more than total of "n" jumps for the entire outer "for loop" bcz it's only moving forward
        // Thus, TIME COMPLEXITY = O(n + n) = O(n)
        
        // if the next greater element of the current element is in the window
        while(nextGreaterElement[j] < i + k){
            // move j to that next greater element. Repeat the process until j point to 
            // the max element in the current window
            j = nextGreaterElement[j];
        }
        
        // when the above while loop ends, j will point to largest element in the window
        // If current element is the largest in the window, then also base case of i = j will handle it.
        
        cout<<arr[j]<<endl;
    }
    
    return 0;
}