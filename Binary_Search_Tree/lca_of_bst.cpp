// Both the below implementation is correct. 
// It's just my BST is made differently....


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


bool find(Node* root, int key, vector <int>& path)
{
    if(root == NULL){
        return false;
    }
    
    if(key > root->data){
        //if the data is found in the right subtree of the current node, include the current node in the node to root path.
        if(find(root->right, key, path)){
            path.push_back(root->data);
            return true;
        }
    }
    
    else if(key < root->data){
        //if the data is found in the right subtree of the current node, include the current node in the node to root path.
        if(find(root->left, key, path)){
            path.push_back(root->data);
            return true;
        }
    }
    
    else{
        // current node->data == key. Thus, push this to node to root path
        path.push_back(root->data);
        return true;
    }
    
    return false;
}


int LCA1(Node *root, int x, int y)
{
    vector <int> xToRootPath;
    find(root, x, xToRootPath);
    
    vector <int> yToRootPath;
    find(root, y, yToRootPath);
    
    // for(int i = 0; i < xToRootPath.size(); i++){
    //     cout<<xToRootPath[i]<<" ";
    // }
    // cout<<endl;
    
    // for(int i = 0; i < yToRootPath.size(); i++){
    //     cout<<yToRootPath[i]<<" ";
    // }
    // cout<<endl;
    
    // traverse the node to root paths from behind
    int i = xToRootPath.size() - 1;
    int j = yToRootPath.size() - 1;
    
    while(xToRootPath[i] == yToRootPath[j]){
        i--;
        j--;
    }
    
    // go to the last common element. That's the node where the path diverged => LCA
    i++;
    return xToRootPath[i];
}


int LCA2(Node* root, int x, int y)
{
    if(root == NULL){
        return -1;
    }
    
    // if both lie on the left side of the current node, go to the left
    if(x < root->data && y < root->data){
        return LCA2(root->left, x, y);
    }
    
    // if both lie on the right side of the current node, go to the right
    else if(x > root->data && y > root->data){
        return LCA2(root->right, x, y);
    }
    
    // else, the current node is the node where paths of x and y DIVERGE.
    // NOTE: Skipping the <= (or >=) sign in above "if-elseif" condition will ensure that we handle the case where x is LCA of x & y or vice-versa
    else{
        return root->data;
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
    
    // sort the arr
    sort(arr.begin(), arr.end());
    
    // pass arr, lo, hi
    root = constructBST(arr, 0, arr.size()-1);
    
    int d1, d2;
    cin>>d1>>d2;
    
    // cout<<LCA1(root, d1, d2);
    cout<<LCA2(root, d1, d2);
    
    // display(root);
    
    return 0;
}