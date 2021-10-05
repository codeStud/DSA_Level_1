// NOTE NOTE: Another good approach to this problem - 
// https://www.youtube.com/watch?v=nPtARJ2cYrg

#include<iostream>
#include<string>
#include<vector>
#include<stack>
#include<queue>
#include<utility>
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


Node* construct(int *arr, int n)
{
    root = getNode(arr[0]);
    pair <Node*, int> rootPair = make_pair(root, 1);
    
    stack <pair<Node*, int>> st;
    st.push(rootPair);
    
    int idx = 0;
    while(idx < n && !st.empty()){
        pair<Node*, int> topPair = st.top();

        if(topPair.second == 1){
            // go to the next element in the arr
            idx += 1;
            
            if(arr[idx] != -1){
                // create left node of the node at stack top. Since, first element of pair is a pointer, adding child to the topPair variable will also reflected in stack.
                topPair.first->left = getNode(arr[idx]);
                
                // create pair of the newly created node
                pair <Node*, int> leftPair = make_pair(topPair.first->left, 1);
                
                // topPair is the local variable and writing topPair.second++ won't change the value of this pair in the stack. So, change it like this. (Before pushing the newly created node)
                st.top().second++;
                
                st.push(leftPair);    
            }
            
            else{
                // Since, first element of pair is a pointer, adding child to the topPair variable will also reflected in the stack.
                topPair.first->left = NULL;
                // topPair is the local variable and writing topPair.second++ won't change the value of this pair in the stack. So, change it 
                // like this.
                st.top().second++;
            }
            
        }
        
        else if(topPair.second == 2){
            // go to the next element in the array
            idx += 1;
            
            if(arr[idx] != -1){
                // create the left node of the node at stack top. Since, first element of pair is a pointer, adding child to the topPair variable
                // will also reflected in the stack.
                topPair.first->right = getNode(arr[idx]);
                
                pair <Node*, int> rightPair = make_pair(topPair.first->right, 1);
                
                st.top().second++;
                
                // topPair is the local variable and writing topPair.second++ won't change the value of this pair in the stack. So, change it like this. (Before pushing the newly created node)
                st.push(rightPair);    
            }
            
            else{
                st.top().second++;
                topPair.first->right = NULL;
            }

        }
        
        else{
            st.pop();
        }
        
    }
    
    return root;
}


void display(Node *root)
{
    if(root == NULL){
        return;
    }
    
    string str = "";                                                                                    
    str += root->left == NULL ? "." : to_string(root->left->data);
    str += " <- " + to_string(root->data) + " -> ";
    str += root->right == NULL ? "." : to_string(root->right->data);
    cout<<str<<endl;
    
    display(root->left);
    display(root->right);
}


bool find(Node *root, int key, vector<Node*>& path)
{
    if(root == NULL){
        return false;
    }
    
    if(root->data == key){
        path.push_back(root);
        
        return true;
    }
    
    bool findInLeft = find(root->left, key, path);
    if(findInLeft){
        // add to path
        path.push_back(root);
        
        return true;
    }
    
    bool findInRight = find(root->right, key, path);
    if(findInRight){
        // add to path
        path.push_back(root);
        
        return true;
    }
    
    // neither found in root, left, right
    return false;
}


void printKLevelDown(Node *root, int k, Node* blocker)
{
    if(root == NULL || k < 0 || root == blocker){
        return;
    }
    
    if(k == 0){
        cout<<root->data<<endl;
    }
    
    printKLevelDown(root->left, k-1, blocker);
    printKLevelDown(root->right, k-1, blocker);
    
}


void kDistanceAway(Node *root, int key, int k, vector<Node*>& path)
{
    // find node to root path for key
    if(find(root, key, path)){
    
         // for each element in path, print k-i distance away nodes
        for(int i = 0; i < path.size(); i++){
            // pass left element as blocker
            printKLevelDown(path[i], k-i, i == 0? NULL : path[i-1]);    
        }
    
    }
    
}


int main()                                                                                      
{
    int n;
    cin>>n;
    
    int arr[n];
    for(int i = 0; i < n; i++){
        string x;
        cin>>x;
        if(x != "n"){
            // convert the string to integer and push it to array
            arr[i] = stoi(x);    
        }
        else{
            arr[i] = -1;
        }
    }

    Node* root = construct(arr, n);
    // display(root);
    
    vector <Node*> path;
    
    int key, k;
    cin>>key>>k;
    
    kDistanceAway(root, key, k, path);
    
    return 0;
}