#include<iostream>
#include<vector>
#include<string>
#include<stack>
#include<queue>
#include<algorithm>
#include<climits>
using namespace std;

struct Node{
    int data;
    vector <Node*> child;
};
Node *root = NULL;


Node* getNode(int data)
{
    Node *temp = new Node();
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
            // create Node
            Node *newNode = getNode(arr[i]);
            
            // make it child of node at stack top
            if(!st.empty()){
                st.top()->child.push_back(newNode);
            }
            else{
                // this is the root node
                root = newNode;
            }
            
            // push newNode to stack
            st.push(newNode);
        }
    }
}


void display(Node *root)
{
    // print root's data
    string str = to_string(root->data) + " -> ";
    
    // print root's child
    for(Node *child : root->child){
        str += to_string(child->data) + ", ";
    }
    str += ".";
    cout<<str<<endl;
    
    // call display for child nodes recursively
    for(Node *child : root->child){
        display(child);
    }
    
}


/*
Node* getTail(Node *root)
{
    // travel down the chain
    while(root->child.size() == 1){
        root = root->child[0];
    }
    
    return root;
}


//``````O(N*N)```````
void linearize(Node *root)
{
    // linearize the child nodes
    for(Node *child : root->child){
        linearize(child);
    }
    
    // linearize the root
    while(root->child.size() > 1){
        Node *lastChild = root->child[root->child.size() - 1];
        // remove the last child node
        root->child.pop_back();
        
        // 2nd last child is at last index now
        Node *secondLastChild = root->child[root->child.size() - 1];
        
        // get the tail of the 2nd last child node
        Node *tail = getTail(secondLastChild);
        
        // attach tail to last child of current node
        tail->child.push_back(lastChild);
    }
}
*/


//`````` O(N)```````
// linearize2 : It linearizes the node and returns the tail of the linearized node simultaneously
Node* linearize2(Node *root)
{
    if(!root || root->child.size() == 0){
        return root;
    }
    
    // linearize the last child (and collect it's tail)
    // To understand why we're returning tailOfLast, in the example tree - for node 30, we need it's tail
    // to connect to node 40. Now, tail of 30 will be the tailOfLast of 30 and similarly for other nodes, tail
    // of each node will be the tail of it's last child. Thus, store the tailOfLast before popping it in the while loop
    // below and then return this tailOfLast at the end.
    
    Node* tailOfLast = linearize2(root->child[root->child.size() - 1]);
    
    while(root->child.size() > 1){
        // keep the reference to last child and pop this child
        Node* lastChild = root->child[root->child.size() - 1];
        root->child.pop_back();
        
        Node* secondLastChild = root->child[root->child.size() - 1];
        // linearize the secondLastChild and collect it's tail
        Node* tailOfSecondLast = linearize2(secondLastChild);
        
        // last child will become the child of the "tail" of secondLastChild
        tailOfSecondLast->child.push_back(lastChild);
    }
    
    // Since the function returns the tail of the linearized node, on the top level,
    // root is being linearized. So, return the overall tail (i.e tail of the last child).
    return tailOfLast;
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
    
    // linearize(root);
    linearize2(root);
    display(root);

    return 0;
}