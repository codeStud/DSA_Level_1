#include<iostream>
#include<stack>
#include<string>
#include<climits>
#include<algorithm>
#include<vector>
using namespace std;

int floorVal;
int ceilVal;

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


void ceilAndFloor(Node *root, int key)
{
    if(root->data < key){
        floorVal = max(floorVal, root->data);
    }
    else if(root->data > key){
        ceilVal = min(ceilVal, root->data);
    }
    
    for(Node *child : root->child){
        ceilAndFloor(child, key);
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
    
    int key;
    cin>>key;
    
    constructTree(arr, n);
    // display(root);
    
    floorVal = INT_MIN;  // Initialize to min because we will use max() on it
    ceilVal = INT_MAX;  // Initialize to max because we will use min() on it
    
    ceilAndFloor(root, key);
    
    cout<<"CEIL = "<<ceilVal<<endl;
    cout<<"FLOOR = "<<floorVal<<endl;
        
    return 0;
}