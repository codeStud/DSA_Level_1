#include<iostream>
#include<stack>
#include<string>
#include<climits>
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


// this function is returning height of the child nodes and calculating diameter
// in the process.
int diameterOfTree(Node *root)
{
    int maxHeight = -1;
    int secondMaxHeight = -1;
    
    // find max and second max height amongst all the children
    for(Node *child : root->child){
        int curHeight = diameterOfTree(child);
        
        if(curHeight > maxHeight){
            secondMaxHeight = maxHeight;
            maxHeight = curHeight;
        } else if(curHeight > secondMaxHeight){
            secondMaxHeight = curHeight;
        }
        
    }
    
    // diameter passing through the current root
    int potentialDiameter = maxHeight + secondMaxHeight + 2;
    
    // But diameter of the entire Tree need not pass through the root node of tree
    // Take the max of all the potentialDiameters
    if(potentialDiameter > diameter){
        diameter = potentialDiameter;
    }
    
    // this function is returning height of the child nodes and calculating diameter
    // in the process. So, height = height of deepest child + 1
    maxHeight = maxHeight + 1;
    
    // return your height
    return maxHeight;
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
    
    diameter = 0;
    
    diameterOfTree(root);
    cout<<diameter<<endl;
    
    return 0;
}