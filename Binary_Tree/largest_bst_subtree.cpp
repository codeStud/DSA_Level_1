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


class BSTPair{
    public:
        bool isTreeBST;
        int minVal;
        int maxVal;
        int largestBSTRoot;
        int largestBSTSize;
};

BSTPair largest_BST_Subtree(Node *root)
{
    if(root == NULL){
        BSTPair basePair;
        
        basePair.isTreeBST = true;
        basePair.minVal = INT_MAX;
        basePair.maxVal = INT_MIN;
        basePair.largestBSTRoot = -1;
        basePair.largestBSTSize = 0;
        
        return basePair;
    }
    
    // will return the BSTPair with all the values set for left and right subtrees
    BSTPair leftPair = largest_BST_Subtree(root->left);
    BSTPair rightPair = largest_BST_Subtree(root->right);
    
    // create BSTPair for root node and set the values
    BSTPair rootPair;
    
    rootPair.isTreeBST = (root->data >= leftPair.maxVal && root->data <= rightPair.minVal) && (leftPair.isTreeBST) && (rightPair.isTreeBST);
    
    rootPair.minVal = min({root->data, leftPair.minVal, rightPair.minVal});
    rootPair.maxVal = max({root->data, leftPair.maxVal, rightPair.maxVal});
    
    // if the tree rooted at current node is BST => root of largest bst = current node
    // and size of largest BST = left size + right size
    if(rootPair.isTreeBST){
        rootPair.largestBSTRoot = root->data;
        rootPair.largestBSTSize = 1+ leftPair.largestBSTSize + rightPair.largestBSTSize;
    }
    // set values of current pair as per the largest bst amongst left/right subtree
    else if(leftPair.largestBSTSize > rightPair.largestBSTSize){
        rootPair.largestBSTRoot = leftPair.largestBSTRoot;
        rootPair.largestBSTSize = leftPair.largestBSTSize;
    }
    else{
        rootPair.largestBSTRoot = rightPair.largestBSTRoot;
        rootPair.largestBSTSize = rightPair.largestBSTSize;    
    }
    
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
    
    BSTPair finalPair;
    finalPair = largest_BST_Subtree(root);
    
    cout<<finalPair.largestBSTRoot<<"@"<<finalPair.largestBSTSize<<endl;
    
    return 0;
}