// This solution is of complexity O(n) bcz we are iterating over the array once and each element will be pushed
// and popped exactly one time in the stack. Thus O(n + k) = O(n)

#include<iostream>
#include<stack>
using namespace std;

int main()
{
    int n;
    cin>>n;
    
    int arr[n];
    for(int i = 0; i < n; i++){
        cin>>arr[i];
    }
    
    int res[n];
    stack <int> st;
    
    // last element doesn't have any greater element to the right
    res[n-1] = -1;
    st.push(arr[n-1]);
    
    for(int i = n-2; i >= 0; i--){
        // pop while stack isn't empty and stack top is smaller
        while((!st.empty()) && st.top() <= arr[i]){
            st.pop();
        }
        
        // if stack empty then no greater element to the right
        if(st.empty()){
            res[i] = -1;
        }
        else{
            // else stack top is the next greater to the right
            res[i] = st.top();
        }
        
        // push the current element before moving left
        st.push(arr[i]);
    }
    
    for(int i = 0; i < n; i++){
        cout<<res[i]<<endl;
    }
    
    return 0;
}