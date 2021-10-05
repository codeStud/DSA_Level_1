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

/*
int sumOfSubtree(Node *root)
{
    if(root == NULL){
        return 0;
    }
    
    return root->data + sumOfSubtree(root->left) + sumOfSubtree(root->right);
}


void calcTilt(Node *root, int& treeTilt)
{
    if(root == NULL){
        return;
    }
    
    // get the left and right subtree sum
    int leftSum = sumOfSubtree(root->left);
    int rightSum = sumOfSubtree(root->right);
    
    // calculate the tilt for the current node
    int nodeTilt = abs(leftSum - rightSum);
    
    // calculate the tilt for the entire tree
    treeTilt += nodeTilt;
    
    // recursively calculate the tilt for left and right subtree
    calcTilt(root->left, treeTilt);
    calcTilt(root->right, treeTilt);
}
*/


int calcTiltReturnSum(Node* root, int& treeTilt)
{
    if(root == NULL){
        return 0;
    }
    
    // below call will return the sum of left (and right) subtree
    int leftSum = calcTiltReturnSum(root->left, treeTilt);
    int rightSum = calcTiltReturnSum(root->right, treeTilt);
    
    // calculate the tilt of the current node
    int nodeTilt = abs(leftSum - rightSum);
    
    // update the treeTilt
    treeTilt += nodeTilt;
    
    // return the sum of the entire sub-tree ROOTED AT current node.
    // This will make this function work and not having to write separate function to calculate subtreeSum().
    return root->data + leftSum + rightSum;
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
    
    // int treeTilt = 0;
    // calcTilt(root, treeTilt);  
    // cout<<treeTilt<<endl;
    
    int treeTilt = 0;
    calcTiltReturnSum(root, treeTilt);
    
    cout<<treeTilt<<endl;
    
    return 0;
}