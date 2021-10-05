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
// Method - 1
int height(Node *root)
{
    if(root == NULL){
        return -1;
    }
    
    return 1 + max(height(root->left), height(root->right));
}

bool isBalanced(Node *root)
{
    if(root == NULL){
        return true;
    }
    
    int leftHeight = height(root->left);
    int rightHeight = height(root->right);
    
    // check if the tree rooted at current node is balanced or not
    if(abs(leftHeight - rightHeight) <= 1){
        // check if the left and right subtree are balanced
        return isBalanced(root->left) && isBalanced(root->right);
    }
    
    // if current node itself is not balanced, no need to look at the subtrees.
    else{
        return false;
    }
}

*/

/*
// METHOD - 2
class BalPair{
    public:
        int ht;
        bool isBal;
};

BalPair isTreeBalanced(Node *root)
{
    if(root == NULL){
        BalPair basePair;
        basePair.ht = -1;
        basePair.isBal = true;

        return basePair;
    }

    BalPair leftPair = isTreeBalanced(root->left);
    BalPair rightPair = isTreeBalanced(root->right);

    BalPair curPair;

    curPair.ht = max(leftPair.ht, rightPair.ht) + 1;
    curPair.isBal = leftPair.isBal && rightPair.isBal && abs(leftPair.ht - rightPair.ht) <= 1;

    return curPair;
}

*/

// Method - 3
int checkBalancedReturnHeight(Node *root, bool& balanced)
{
    if(root == NULL){
        return -1;
    }
    
    int leftHeight = checkBalancedReturnHeight(root->left, balanced);
    int rightHeight = checkBalancedReturnHeight(root->right, balanced);
    
    // make the change in balanced variable during the euler path (recursive call)
    if(abs(leftHeight - rightHeight) > 1){
        balanced = false;
    }
    
    // calculate the height of the current node
    int curHeight = 1 + max(leftHeight, rightHeight);
    
    // return current Node height. Due to this, you won't have to right a separate function for calculating the height.
    return curHeight;
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
    
    // Method - 1

    // if(isBalanced(root)){
    //     cout<<"true";
    // }
    // else{
    //     cout<<"false";
    // }
    
    // Method - 2
    // BalPair rootPair = isTreeBalanced(root);
    // if(rootPair.isBal){
    //     cout<<"true";
    // }
    // else{
    //     cout<<"false";
    // }

    // Method - 3
    // initally balanced is true for null tree
    bool balanced = true;
    checkBalancedReturnHeight(root, balanced);
    
    if(balanced){
        cout<<"true";
    }
    else{
        cout<<"false";
    }
    
    return 0;
}