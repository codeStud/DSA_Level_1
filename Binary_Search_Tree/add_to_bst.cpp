// Correct Implementation
// Just the BST Constructed is different (But Correct)

#include<iostream>
#include<vector>
#include<string>
#include<stack>
#include<climits>
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


Node* constructBST(vector<int> arr, int lo, int hi)
{
   if(lo > hi){
       return NULL;
   }
   
   int mid = lo + (hi - lo)/2;
   Node *root = new Node();
   
   // make mid as the current node
   root->data = arr[mid];
   // create left subtree from left part of arr
   root->left = constructBST(arr, lo, mid-1);
   // create right subtree from right part of arr
   root->right = constructBST(arr, mid+1, hi);
   
   // if you look at the higher level analysis, you are creating the root, setting it's left and right subtree and returning the root. In low level analysis also, you'll find that you are actually returning the root of the entire tree.
   return root;
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


Node* addNode(Node* root, int data)
{
    if(root == NULL){
        return getNode(data);
    }

    if(data > root->data){
        // insert in right subtree
        root->right = addNode(root->right, data);
    }
    else if(data < root->data){
        // insert in left subtree
        root->left = addNode(root->left, data);
    }
    else{
        // do nothing
    }

    return root;
}


int main()
{
    int n;
    cin>>n;
    
    vector <int> arr;
    for(int i = 0; i < n; i++){
        string temp;
        cin>>temp;
        if(temp == "n"){
            // ignore null values
            continue;
        }
        else{
            arr.push_back(stoi(temp));
        }
    }
    
    int key;
    cin>>key;
    
    // sort the arr
    sort(arr.begin(), arr.end());
    
    // pass arr, lo, hi
    root = constructBST(arr, 0, arr.size()-1);

    // modify root if in case tree is empty
    root = addNode(root, key);
    
    display(root);
    
    return 0;
}