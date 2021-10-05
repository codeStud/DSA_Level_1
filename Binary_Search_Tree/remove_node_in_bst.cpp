// CORRECT SOLUTION, 
// JUST THE BST CONSTRUCTION IS DIFFERENT (But Correct!)


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


int maxNode(Node *root)
{
    if(root->right){
        return maxNode(root->right);
    }
    else{
        return root->data;
    }
}


Node* deleteNode(Node* root, int key)
{
    if(root == NULL){
        return root;
    }
    
    if(root->data > key){
        root->left = deleteNode(root->left, key);
    }
    else if(root->data < key){
        root->right = deleteNode(root->right, key);
    }
    // key found
    else{
        //1. current node has 2 child
        if(root->left != NULL && root->right != NULL){
            // set current node as max in left subtree
            int maxVal = maxNode(root->left);
            root->data = maxVal;
            
            // delete the maxVal from the left subtree & receive the modified root
            root->left = deleteNode(root->left, maxVal);
            
            return root;
        }
        
        //2. current node has ONLY left child
        else if(root->left != NULL){
            // attach left child of current node to the parent of current node
            return root->left;
        }
        
        //3. current node has ONLY right child
        else if(root->right != NULL){
            // attach right child of current node to the parent of current node
            return root->right;
        }
        
        //4. current node is a leaf
        else{
            return NULL;
        }
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
    
    root = deleteNode(root, key);
    
    display(root);
    
    return 0;
}