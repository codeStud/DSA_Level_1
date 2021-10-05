#include<iostream>
#include<vector>
#include<string>
#include<stack>
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


void levelOrderLinewiseZigzag(Node *root)
{
    int level = 1;
    stack <Node*> s1;
    stack <Node*> s2;
    
    s1.push(root);
    
    while(!s1.empty()){
        cout<<s1.top()->data<<" ";
        // for odd levels, add child nodes from left to right => while popping and printing, they'll appear right to left, as desired
        if(level % 2 != 0){
            for(int i = 0; i < s1.top()->child.size(); i++){
                s2.push(s1.top()->child[i]);
            }
        }
        
        // for even levels, add child nodes right to left => while popping and printing, they'll appear left to right, i.e as desired
        else{
            for(int i = s1.top()->child.size() - 1; i >= 0; i--){
                s2.push(s1.top()->child[i]);
            }
        }
        
        s1.pop();
        
        if(s1.empty()){
            stack <Node*> temp = s1;
            s1 = s2;
            s2 = temp;
            level += 1;
            cout<<endl;
        }
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
        
    levelOrderLinewiseZigzag(root);

    return 0;
}