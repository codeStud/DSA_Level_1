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



int size(Node* root)
{
    if(root == NULL){
        return 0;
    }
    
    int leftSize = size(root->left);
    int rightSize = size(root->right);
    
    return leftSize + rightSize + 1;
}


int sum(Node* root)
{
    if(root == NULL){
        return 0;
    }
    
    int leftSum = sum(root->left);
    int rightSum = sum(root->right);
    
    return leftSum + rightSum + root->data;
}


int maxVal(Node* root)
{
    if(root->right != NULL){
        return maxVal(root->right);
    }
    else{
        return root->data;
    }
}


int minVal(Node* root)
{
    if(root->left != NULL){
        return minVal(root->left);
    }
    else{
        return root->data;
    }
}


bool find(Node* root, int key)
{
    if(root == NULL){
        return false;
    }
    
    if(root->data == key){
        return true;
    }
    
    else if(root->data < key){
        return find(root->right, key);
    }
    
    else{
        return find(root->left, key);
    }
    
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
    
    // display(root);
    
    cout<<size(root)<<endl;
    cout<<sum(root)<<endl;
    cout<<maxVal(root)<<endl;
    cout<<minVal(root)<<endl;
    
    if(find(root, key)){
        cout<<"true"<<endl;
    }
    else{
        cout<<"false"<<endl;
    }
    
    
    return 0;
}