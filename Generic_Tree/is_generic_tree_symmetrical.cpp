#include<iostream>
#include<vector>
#include<string>
#include<stack>
#include<queue>
#include<algorithm>
#include<climits>
using namespace std;

struct Node{
    int data;
    vector <Node*> child;
};


Node* getNode(int data)
{
    Node *temp = new Node();
    temp->data = data;
    return temp;
}


Node* constructTree(int *arr, int n)
{
    Node *root = NULL;
    
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
    return root;
}


void display(Node *root)
{
    // print root's data
    string str = to_string(root->data) + " -> ";
    
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


bool areMirrorTree(Node* root1, Node *root2)
{
    if(root1->child.size() != root2->child.size()){
        return false;
    }
    
    for(int i = 0, j = root2->child.size() - 1; i < root1->child.size(); i++, j--){
        bool res = areMirrorTree(root1->child[i], root2->child[j]);
        if(!res){
            return false;
        }
    }
    
    return true;
}


bool isSymmetricTree(Node *root)
{
    // SYMMETRIC TREES ARE MIRROR IMAGE OF ITSELF
    return areMirrorTree(root, root);
}


int main()
{
    int n;
    cin>>n;
    
    int arr1[n];
    for(int i = 0; i < n; i++){
        cin>>arr1[i];
    }
    
    Node *root1 = constructTree(arr1, n);

    if(isSymmetricTree(root1)){
        cout<<"true";
    }else{
        cout<<"false";
    }
    
    return 0;
}