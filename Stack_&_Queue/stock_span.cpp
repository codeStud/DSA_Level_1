#include<iostream>
#include<stack>
#include<vector>
#include<utility>
using namespace std;

void stockSpan(vector<int>& arr, vector<int>& span)
{
    // stack will store the index and not the element
    stack <int> st;
    st.push(0);
    span[0] = 1;
    
    for(int i = 1; i < arr.size(); i++){
        // pop all the elements smaller than (or equal to) the current element
        while(!st.empty() && arr[i] >= arr[st.top()]){
            st.pop();
        }
        
        if(st.empty()){
           // no smaller element to the left
           span[i] = i + 1;
        }
        else{
            span[i] = i - st.top();
        }
        
        // push the index of the current element at last
        st.push(i);
    }
}

int main()
{
    int n;
    cin>>n;
    
    vector <int> arr(n);
    for(int i = 0; i < n; i++){
        cin>>arr[i];
    }
    
    vector <int> span (n);
    
    stockSpan(arr, span);
    
    for(int el : span){
        cout<<el<<endl;
    }
    
    
    return 0;
}