#include<iostream>
#include<stack>
using namespace std;

int main()
{
    int n;
    cin>>n;
    
    // input array is an array of characters and not an integer
    char arr[n][n];
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cin>>arr[i][j];
        }
    }
    
    stack <int> st;
    for(int i = 0; i < n; i++){
        // push all the persons into the stack
        st.push(i);
    }
    
    
    
    // while there are at-least 2 persons in the stack
    while(st.size() >= 2){
        // pop 2 persons from stack
        int p2 = st.top();      // p2 on top
        st.pop();
        int p1 = st.top();      // p1 after p2
        st.pop();
        
        // if p1 knows p2 => p1 can't be a celebrity
        if(arr[p1][p2] == '1'){
            // push back p2 (potential celebrity)
            st.push(p2);
        }
        
        // if p1 doesn't know p2 => p2 can't be a celebrity
        else{
            // push back p1 (potential celebrity)
            st.push(p1);
        }
        
    }
    
    // only 1 candidate remains in stack. Check is he's known by all and he doesn't know anyone
    int x = st.top();
    st.pop();
    
    for(int i = 0; i < n; i++){
        if(i != x){
            if(arr[i][x] == '0' || arr[x][i] == '1'){
                cout<<"none"<<endl;
                return 0;
            }
        }
    }
    
    cout<<x<<endl;
    
    return 0;
}