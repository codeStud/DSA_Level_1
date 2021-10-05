// Time Complexity: O(n + n + n) = O(n)

#include<iostream>
#include<stack>
using namespace std;

void nextSmallerRightElement(int *arr, int n, int *smallerRight)
{
    stack <int> st;
    
    // calculating next SMALLER element to the right
    // for right-most element, write 'n' & NOT -1 so that you can calculate the width
    smallerRight[n-1] = n;
    
    // Push INDEX of rightmost element
    st.push(n-1);
    
    for(int i = n-2; i >= 0; i--){
        // pop greater elements to the right
        while(!st.empty() && arr[i] <= arr[st.top()]){
            st.pop();
        }
        if(st.empty()){
            // put 'n' if NO smallerRight element found
            smallerRight[i] = n;
        }
        else{
            // Put the INDEX of the next smaller element to right
            smallerRight[i] = st.top();
        }
        
        // Push INDEX of the current element
        st.push(i);
    }
}

void nextSmallerLeftElement(int *arr, int n, int *smallerLeft)
{
    stack <int> st;
    
    // calculating next SMALLER element to the left
    // for left-most element, write '-1' so that you can calculate the width
    smallerLeft[0] = -1;
    
    // Push INDEX of leftmost element
    st.push(0);
    
    for(int i = 1; i < n; i++){
        // pop greater elements to the left
        while(!st.empty() && arr[i] <= arr[st.top()]){
            st.pop();
        }
        if(st.empty()){
            // put '-1' if NO smaller element to the left is found
            smallerLeft[i] = -1;
        }
        else{
            // Put the INDEX of the next smaller element to left
            smallerLeft[i] = st.top();
        }
        
        // Push INDEX of the current element
        st.push(i);
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
    
    // Left Boundary of rectangle = next smaller element to the left of the current bar
    // Right Boundary of rectangle = next SMALLER element to right of the current bar
    
    int smallerRight[n];  // will store the INDEX of the next smaller element to right
    int smallerLeft[n];   // will store the INDEX of the next smaller element to left
    
    nextSmallerRightElement(arr, n, smallerRight);
    
    nextSmallerLeftElement(arr, n, smallerLeft);
    
    // Now for the rectangle formed by each of the BAR in Histogram - 
    // Length = already given in arr
    // width = smallerRight[i] - smallerLeft[i] - 1;
    
    int maxAreaRect = 0;
    for(int i = 0; i < n; i++){
        int length = arr[i];
        int breadth = smallerRight[i] - smallerLeft[i] - 1;
        int area = length * breadth;
        
        maxAreaRect = max(maxAreaRect, area);
    }
    
    cout<<maxAreaRect;
    
    return 0;
}