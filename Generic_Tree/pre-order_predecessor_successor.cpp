#include<iostream>
#include<stack>
#include<string>
#include<climits>
#include<algorithm>
#include<vector>
using namespace std;

struct Node{
    int data;
    vector <Node*> child;
};
Node *root = NULL;

Node* predecessor = NULL;
Node* successor = NULL;
int state = 0;

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


// Predecessor = Last node when state was = 0
// Successor = First node visited (apart from "key" node) after the state is = 1

void predecessorAndSuccessor(Node* root, int key)
{
    // Keep state 0 until you find the key
    if(state == 0){
        // change the value of state to 1 when you find key
        if(root->data == key){
            state = 1;
        }
        else{
            // keep moving the predecessor ahead
            predecessor = root;
        }
    }
    // it won't run immediately after making state = 1 bcz it's "if - else if"
    else if(state == 1){
        // Now you are at successor
        successor = root;
        // change the value of the state
        state = 2;
    }
    
    for(Node *child : root->child){
        predecessorAndSuccessor(child, key);
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
    
    constructTree(arr, n);
    // display(root);
    
    int key;
    cin>>key;
    
    predecessorAndSuccessor(root, key);
    
    if(predecessor){
        cout<<"Predecessor = "<<predecessor->data<<endl;
    }
    else{
        cout<<"Predecessor = Not found"<<endl;    
    }
    
    if(successor){
        cout<<"Successor = "<<successor->data<<endl;
    }
    else{
        cout<<"Successor = Not found"<<endl;
    }
    
    return 0;
}