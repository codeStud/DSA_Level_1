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
bool isBST(Node *root, int lo, int hi)
{
    if(root == NULL){
        return true;
    }
    
    // allowing duplicate in the left-subtree (<= hi)
    if(root->data > lo && root->data <= hi){
        return isBST(root->left, lo, root->data) &&
               isBST(root->right, root->data, hi);
    }
    
    return false;
}
*/


class BSTPair{
    public:
        bool isTreeBST;
        int minVal;
        int maxVal;
};

BSTPair isBST(Node *root)
{
    if(root == NULL){
        BSTPair basePair;
        basePair.isTreeBST = true;
        basePair.minVal = INT_MAX;
        basePair.maxVal = INT_MIN;
        
        return basePair;
    }
    
    // will return the BSTPair with all the values set for left and right subtrees
    BSTPair leftPair = isBST(root->left);
    BSTPair rightPair = isBST(root->right);
    
    // create BSTPair for root node and set the values
    BSTPair rootPair;
    
    rootPair.isTreeBST = (root->data >= leftPair.maxVal && root->data <= rightPair.minVal) && (leftPair.isTreeBST) && (rightPair.isTreeBST);
    
    rootPair.minVal = min({root->data, leftPair.minVal, rightPair.minVal});
    rootPair.maxVal = max({root->data, leftPair.maxVal, rightPair.maxVal});
    
    // return this rootPair as BSTPair is the return type for this function
    return rootPair;
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
    
    // if(isBST(root, INT_MIN, INT_MAX)){
    //     cout<<"true";
    // }
    // else{
    //     cout<<"false";
    // }
    
    BSTPair finalPair;
    finalPair = isBST(root);
    
    if(finalPair.isTreeBST){
        cout<<"true";
    }
    else{
        cout<<"false";
    }
    
    return 0;
}