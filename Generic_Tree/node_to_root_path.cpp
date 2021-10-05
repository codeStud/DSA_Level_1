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


vector<int> nodeToRootPath(Node* root, int key)
{
    if(root->data == key){
        vector <int> res;
        res.push_back(root->data);
        return res;
    }
    
    for(Node *child : root->child){
        vector <int> ans = nodeToRootPath(child, key);
        
        // if key if found => ans will have elements inside it
        if(ans.size() > 0){
            // add the current node value to the list and return
            ans.push_back(root->data);
            return ans;
        }
    }
    
    // return empty list if not found
    vector <int> noneFound;
    return noneFound;
}


int main()
{
    int n;
    cin>>n;
    
    int arr[n];
    for(int i = 0; i < n; i++){
        cin>>arr[i];
    }
    
    int key;
    cin>>key;
    
    constructTree(arr, n);

    vector <int> ans = nodeToRootPath(root, key);
    int cnt = 0;

    cout << '[';
    for (int str : ans){
        if (cnt != ans.size() - 1)
            cout << str << ", ";
        else
            cout << str;
        cnt++;
    }
    cout << ']';
    
    return 0;
}