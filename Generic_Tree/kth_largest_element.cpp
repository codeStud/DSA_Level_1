#include<iostream>
#include<stack>
#include<string>
#include<climits>
#include<algorithm>
#include<vector>
using namespace std;

int floorVal;

struct Node{
    int data;
    vector <Node*> child;
};
Node *root = NULL;


Node* getNode(int data)
{
    Node* temp = new Node();
    temp->data = data;
    return temp;
}


void constructTree(int *arr, int n)
{
    stack <Node*> st;
    
    for(int i = 0; i < n; i++){
        if(arr[i] == -1){
            st.pop();
        }
        else{
            Node *node = getNode(arr[i]);

            if(!st.empty()){
                st.top()->child.push_back(node);
            }
            else{
                root = node;
            }
            
            st.push(node);
        }
        
    }
}


void display(Node *root)
{
    if(root){
        
        string str = to_string(root->data) + "-> ";
        for(Node *child : root->child){
            str += to_string(child->data) + ", ";
        }
        str += ".";
        cout<<str<<endl;
        
        for(Node *child : root->child){
            display(child);
        }
        
    }
}


void findFloor(Node *root, int key)
{
    if(root->data < key){
        floorVal = max(floorVal, root->data);
    }

    for(Node *child : root->child){
        findFloor(child, key);
    }
}

// floor(INT_MAX) == largest element
// floor(largest element) == second largest element
// floor(k+1 th largest element) == kth largest element
int kthLargest(Node *root, int k)
{
    floorVal = INT_MIN;  // Initialize to min because we will use max() on it
    int factor = INT_MAX;
    
    // loop k times
    for(int i = 0; i < k; i++){
        findFloor(root, factor);
        // set factor to the largest element, 2nd largest element and so on...
        factor = floorVal;
        // reset floorVal to INT_MIN to calculate floor of "factor" correctly
        floorVal = INT_MIN;
    }
    
    return factor;
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
    
    constructTree(arr, n);
    // display(root);
    
    cout<<kthLargest(root, k)<<endl;
        
    return 0;
}