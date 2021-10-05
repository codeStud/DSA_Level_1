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


void printSingleChildNode(Node* root)
{
    if(root == NULL){
        return;
    }
    
    if(root->left == NULL && root->right != NULL){
        // print the right child
        cout<<root->right->data<<endl;
    }
    
    else if(root->left != NULL && root->right == NULL){
        // print the left child
        cout<<root->left->data<<endl;
    }
    
    printSingleChildNode(root->left);
    printSingleChildNode(root->right);
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
    
    printSingleChildNode(root);
    
    return 0;
}