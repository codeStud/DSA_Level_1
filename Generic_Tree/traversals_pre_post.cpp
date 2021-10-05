#include<iostream>
#include<vector>
#include<string>
#include<stack>
#include<climits>
using namespace std;

struct Node{
    int data;
    vector <Node*> child;
};
Node *root = NULL;


Node* getNode(int data)
{
    Node *temp = new Node();
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
            // create Node
            Node *newNode = getNode(arr[i]);
            
            // make it child of node at stack top
            if(!st.empty()){
                st.top()->child.push_back(newNode);
            }
            else{
                // this is the root node
                root = newNode;
            }
            
            // push newNode to stack
            st.push(newNode);
        }
    }
}


void display(Node *root)
{
    // print root's data
    string str = to_string(root->data) + "-> ";
    
    // print root's child
    for(Node *child : root->child){
        str += to_string(child->data) + ", ";
    }
    str += ".";
    cout<<str<<endl;
    
    // call display for child nodes recursively
    for(Node *child : root->child){
        display(child);
    }
    
}


void traversals(Node *root)
{
    cout<<"Node Pre "<<root->data<<endl;
    
    // recursive calls for all children
    for(Node *child : root->child){
        cout<<"Edge Pre "<<root->data<<"--"<<child->data<<endl;
        traversals(child);
        cout<<"Edge Post "<<root->data<<"--"<<child->data<<endl;
    }
    
    cout<<"Node Post "<<root->data<<endl;
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
    
    traversals(root);

    return 0;
}