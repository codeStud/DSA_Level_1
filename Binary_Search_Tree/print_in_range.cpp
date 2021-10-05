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


void printInRange(Node* root, int d1, int d2)
{
    if(root == NULL){
        return;
    }
    
    // if d1, d2 are both smaller than current node->data => go ONLY to left + don't print current node
    if(d1 < root->data && d2 < root->data){
        printInRange(root->left, d1, d2);
    }
    
    // if d1, d2 are both greater than current node->data => go ONLY to right + don't print current node
    else if(d1 > root->data && d2 > root->data){
        printInRange(root->right, d1, d2);
    }
    
    // else go both left and right + print in-order to get the output in sorted fashion
    else{
        printInRange(root->left, d1, d2);
        cout<<root->data<<endl;
        printInRange(root->right, d1, d2);
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
 
    printInRange(root, d1, d2);
    
    // display(root);
    
    return 0;
}