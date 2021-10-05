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


bool search(Node *root, int key)
{
    if(root == NULL){
        return false;
    }
    
    if(root->data < key){
        return search(root->right, key);
    }
    else if(root->data > key){
        return search(root->left, key);
    }
    else{
        return true;
    }
}


void targetSumPair_1(Node* root, Node* node, int target)
{
    if(node == NULL){
        return;
    }
    
    targetSumPair_1(root, node->left, target);
    
    // Since we want output sorted => work in INORDER
    int comp = target - node->data;
    
    // to avoid printing permutation of the pair, and printing pair in the 
    // format of (smallerNum, largerNum)
    if(node->data < comp){
        // if comp is present in the BST then we have the pair
        if(search(root, comp) == true){
            cout<<node->data<<" "<<comp<<endl;
        }
    }
    
    targetSumPair_1(root, node->right, target);
}


void targetSumPair_2(Node* root, vector<int>& data)
{
    if(root == NULL){
        return;
    }

    targetSumPair_2(root->left, data);

    // push the node->data in vector in INORDER to keep it sorted
    data.push_back(root->data);

    targetSumPair_2(root->right, data);

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
    
    int target;
    cin>>target;
 
    // METHOD-1 O(N*logN)
    // pass root twice. One will be used to traverse the bst and another 
    // will be kept un-modified so that we can search()

    // targetSumPair_1(root, root, target);


    // METHOD-2 O(N)
    vector <int> data;
    targetSumPair_2(root, data);

    int lo = 0, hi = data.size() - 1;
    while(lo < hi){

        if(target > (data[lo] + data[hi])){
            // move right, since sorted vector & we want to increase the sum
            lo++;
        }
        else if(target < (data[lo] + data[hi])){
            // move left to decrease the sum
            hi--;
        }
        else{
            // we have the pair
            cout<<data[lo]<<" "<<data[hi]<<endl;
            lo++;
            hi--;
        }
        
    }
    
    // display(root);
    
    return 0;
}