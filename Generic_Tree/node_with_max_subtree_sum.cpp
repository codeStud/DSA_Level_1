#include<iostream>
#include<stack>
#include<string>
#include<climits>
#include<algorithm>
#include<vector>
using namespace std;

int maxSum;
int nodeVal;

struct Node{
    int data;
    vector <Node*> child;
};
Node *root = NULL;


Node* getNode(int data)
{
    Node* temp = new Node();
    temp->data = data;
    return temp;
}


void constructTree(int *arr, int n)
{
    stack <Node*> st;
    
    for(int i = 0; i < n; i++){
        if(arr[i] == -1){
            st.pop();
        }
        else{
            Node *node = getNode(arr[i]);

            if(!st.empty()){
                st.top()->child.push_back(node);
            }
            else{
                root = node;
            }
            
            st.push(node);
        }
        
    }
}


void display(Node *root)
{
    if(root){
        
        string str = to_string(root->data) + "-> ";
        for(Node *child : root->child){
            str += to_string(child->data) + ", ";
        }
        str += ".";
        cout<<str<<endl;
        
        for(Node *child : root->child){
            display(child);
        }
        
    }
}


int maximumSumSubtree(Node *root)
{
    // sum of subtree = sum of (root->data + sum of decendents of root)
    int sum = 0;
    
    for(Node *child : root->child){
        int childSubtreeSum = maximumSumSubtree(child);
        // take sum of all the children
        sum += childSubtreeSum;
    }
    
    // add value of the current node 
    sum += root->data;
    
    if(maxSum < sum){
        nodeVal = root->data;
        maxSum = sum;
    }
    
    return sum;
}


int main()
{
    int n;
    cin>>n;
    
    int arr[n];
    for(int i = 0; i < n; i++){
        cin>>arr[i];
    }
    
    constructTree(arr, n);
    // display(root);
    
    maxSum = INT_MIN;
    maximumSumSubtree(root);
    
    cout<<nodeVal<<"@"<<maxSum;
    
    return 0;
}