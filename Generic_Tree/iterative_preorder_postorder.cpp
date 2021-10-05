#include<iostream>
#include<stack>
#include<string>
#include<climits>
#include<utility>
#include<algorithm>
#include<vector>
using namespace std;

int diameter;

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


void iterativePrePost(Node *root)
{
    pair <Node*, int> rootPair = make_pair(root, -1);
    
    stack <pair<Node*, int>> st;
    
    st.push(rootPair);
    
    string pre = "";
    string post = "";
    
    while(!st.empty()){
        // extract the stack top pair
        pair <Node*, int> top = st.top();
        
        // preorder
        if(top.second == -1){
            pre = pre + to_string(top.first->data) + " ";
            // increase the state of this pair IN THE STACK
            // top.second++ won't bring change in the stack
            st.top().second++;
        }
        
        // post-order
        else if(top.second == top.first->child.size()){
            post = post + to_string(top.first->data) + " ";
            // Pop the node after post order
            st.pop();
        }
        
        // preorder is done and child are remaining. So, go to the child at index = 'state' of the node
        else{
            // create pair for the child at the index == state of the current node
            int i = top.second;
            pair <Node*, int> childPair = make_pair(top.first->child[i], -1);
            
            // don't forget to increment the state of the current stack top
            st.top().second++;
            
            // push the child in the stack
            st.push(childPair);
        }
        
    }
    
    cout<<pre<<endl;
    cout<<post<<endl;
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
    
    iterativePrePost(root);
    
    return 0;
}