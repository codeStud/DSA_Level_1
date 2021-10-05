#include<iostream>
#include<stack>
#include<string>
#include<vector>
using namespace std;

struct Node{
    int data;
    vector <Node*> child;
};
Node *root = NULL;


Node* newNode(int val)
{
    Node *temp = new Node;
    temp->data = val;
    return temp;
}


void display(Node *root)
{
    string str = to_string(root->data) + "-> ";
    // visit the current Node's children
    for(auto child : root->child){
        str += to_string(child->data) + ", ";
    }
    str += ".";
    cout<<str<<endl;
    
    // make recursive display calls for all children of current Node
    for(Node *child : root->child){
        display(child);
    }
}


void createGenericTree(int *arr, int n)
{
    stack <Node*> st;
    
    for(int i = 0; i < n; i++){
        if(arr[i] == -1){
            st.pop();
        }
        else{
            // create a new Node
            Node *temp = newNode(arr[i]);
            // make temp a child of Node in stack top
            if(!st.empty()){
                st.top()->child.push_back(temp);
            }
            else{
                // this is the first Node => make it root
                root = temp;
            }
            // push temp into stack
            st.push(temp);
        }
    }
}


int sizeOfTree(Node* root)
{
    int size = 0;
    
    for(Node *child : root->child){
        int childSize = sizeOfTree(child);
        size = size + childSize;
    }
    
    // add 1 for the current node
    size += 1;
    return size;
}


int main()
{
    int n;
    cin>>n;
    
    int arr[n];
    for(int i = 0; i < n; i++){
        cin>>arr[i];
    }
    
    createGenericTree(arr, n);
    
    cout<<sizeOfTree(root);
    
    // cout<<root->child[2]->child[0]->data;
    // display(root);
    
    return 0;
}