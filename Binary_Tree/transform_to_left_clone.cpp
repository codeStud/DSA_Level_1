#include<iostream>
#include<vector>
#include<string>
#include<stack>
#include<algorithm>
using namespace std;

struct Node{
    int data;
    Node *left, *right;
};
Node *root = NULL;

Node* getNode(int data)
{
    Node *temp = new Node();
    temp->data = data;
    temp->left = temp->right = NULL;
    return temp;
}


void constructBT(int *arr, int n)
{
    root = getNode(arr[0]);
    pair <Node*, int> rootPair = make_pair(root, 1);
    
    stack <pair<Node*, int>> st;
    st.push(rootPair);
    
    int idx = 0;
    while(!st.empty()){
        pair <Node*, int> top = st.top();
        
        if(top.second == 1){
            idx += 1;
            
            if(arr[idx] != -1){
                top.first->left = getNode(arr[idx]);
                
                st.top().second++;
                
                pair <Node*, int> leftPair = make_pair(top.first->left, 1);
                st.push(leftPair);
            }
            else{
                top.first->left = NULL;
                st.top().second++;
            }
        }
        
        else if(top.second == 2){
            idx += 1;
            
            if(arr[idx] != -1){
                top.first->right = getNode(arr[idx]);
                
                st.top().second++;
                
                pair <Node*, int> rightPair = make_pair(top.first->right, 1);
                st.push(rightPair);
            }
            else{
                top.first->right = NULL;
                st.top().second++;
            }
        }
        
        else{
            st.pop();
        }
    }
}


void display(Node *root)
{
    if(root == NULL){
        return;
    }
    string str = "";
    
    root->left ? str += to_string(root->left->data) : str += ".";
    str = str + " <- " + to_string(root->data) + " -> ";
    root->right ? str += to_string(root->right->data) : str += ".";
    cout<<str<<endl;
    
    display(root->left);
    display(root->right);
}


// Node* leftClone(Node *root)
// {
//     if(root == NULL){
//         return root;
//     }
    
//     // make left clone for current node
//     Node *newNode = getNode(root->data);
    
//     // set left child of newNode
//     newNode->left = root->left;
    
//     // newNode will become new left child of current node
//     root->left = newNode;
    
//     // recursively clone the left and right subtree. 
//     // Note that left subtree will now be at root->left->left & NOT root->left
//     leftClone(root->left->left);
//     leftClone(root->right);
    
//     return root;
// }


Node* leftClone(Node *root)
{
    if(root == NULL){
        return root;
    }
    
    // recursively clone the left and right subtree
    Node* leftCloneRoot = leftClone(root->left);
    Node* rightCloneRoot = leftClone(root->right);
    
    // make left clone for current node
    Node *newNode = getNode(root->data);
    
    // left child of newNode will be leftRoot
    newNode->left = leftCloneRoot;
    
    // newNode will become new left child of current node
    root->left = newNode;
    
    return root;
}


int main()
{
    int n;
    cin>>n;
    
    int arr[n];
    for(int i = 0; i < n; i++){
        string temp;
        cin>>temp;
        if(temp == "n"){
            arr[i] = -1;
        }
        else{
            arr[i] = stoi(temp);
        }
    }
    
    constructBT(arr, n);
    
    leftClone(root);
    
    display(root);
    
    return 0;
}