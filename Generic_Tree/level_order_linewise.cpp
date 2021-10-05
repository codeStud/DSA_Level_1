#include<iostream>
#include<vector>
#include<string>
#include<stack>
#include<queue>
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
    string str = to_string(root->data) + "-> ";
    
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


void levelOrderLinewise(Node *root)
{
    queue <Node*> q1;
    queue <Node*> q2;
    
    q1.push(root);
    
    while(!q1.empty()){
        cout<<q1.front()->data<<" ";
        
        // add child to q2
        for(Node *child : q1.front()->child){
            q2.push(child);
        }
        
        q1.pop();
        
        if(q1.empty()){
            queue <Node*> temp = q1;
            
            // make q1 point to q2 (Will act as if elements of q2 has been moved to q1)
            q1 = q2;
            
            // make q2 point to temp (Will act as if q2 is empty now after moving elements from q2 to q1)
            q2 = temp;
            
            // change the level
            cout<<endl;
        }
    }
}


void levelOrderLinewise2(Node* root)
{
    queue <Node*> q;
    q.push(root);
    
    while(!q.empty()){
        // find the size of the queue. It'll give you the number of nodes in current level
        int n = q.size();
        
        for(int i = 0; i < n; i++){
            // remove
            Node *cur = q.front();
            q.pop();
            
            // print
            cout<<cur->data<<" ";
            
            // add children
            for(Node *child : cur->child){
                q.push(child);
            }
        }
        
        // when above for loop ends => level change
        cout<<endl;
    }
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
            
    // levelOrderLinewise(root);
    levelOrderLinewise2(root);
    
    return 0;
}