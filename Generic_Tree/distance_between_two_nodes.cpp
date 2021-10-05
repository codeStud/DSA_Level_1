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
        
        // if key if found
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


int distanceBetweenNodes(Node *root, int x, int y)
{
     // get the node to root path for both x and y
    vector <int> pathX = nodeToRootPath(root, x);
    vector <int> pathY = nodeToRootPath(root, y);
    
    int i, j;
    // loop from behind i.e from root to leaf
    for(i = pathX.size()-1, j = pathY.size()-1; i >= 0 && j >= 0; i--, j--){
        if(pathX[i] != pathY[j]){
            break;
        }
    }
    
    // go to the previous common element, i.e lowest common ancestor
    i++;
    j++;    // j++ bcz we looped above from right to left
    
    // Now, i is the distance of X from LCA and j is the distance of Y from LCA
    // Thus, distance between X and Y = i + j
    return i + j;
}


int main()
{
    int n;
    cin>>n;
    
    int arr[n];
    for(int i = 0; i < n; i++){
        cin>>arr[i];
    }
    
    int key1, key2;
    cin>>key1>>key2;
    
    constructTree(arr, n);

    cout<<distanceBetweenNodes(root, key1, key2);
    
    return 0;
}