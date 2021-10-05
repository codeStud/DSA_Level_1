#include<iostream>
#include<string>
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



void iterativePreInPost(Node *root)
{
    if(root == NULL)    
        return;
    
    pair <Node*, int> rootPair = make_pair(root, 1);
    
    stack <pair<Node*, int>> st;
    st.push(rootPair);
    
    string pre = "";
    string in = "";
    string post = "";
    
    while(!st.empty()){
        pair <Node*, int> top = st.top();
        
        // preorder -> state++ -> go to left
        if(top.second == 1){
            pre += to_string(top.first->data) + " ";
            
            // make the change in stack and not the local variable "top"
            st.top().second++;
            
            if(top.first->left){
                pair <Node*, int> leftPair =  make_pair(top.first->left, 1);
                st.push(leftPair);
            }
            
        }
        
        // inorder -> state++ -> go to right (bcz left already visited)
        else if(top.second == 2){
            in += to_string(top.first->data) + " ";
            
            // make the change in stack and not the local variable "top"
            st.top().second++;
            
            if(top.first->right){
                pair <Node*, int> rightPair =  make_pair(top.first->right, 1);
                st.push(rightPair);
            }
        }
        
        else{
            post += to_string(top.first->data) + " ";
            st.pop();
        }
    }
    
    cout<<pre<<endl;
    cout<<in<<endl;
    cout<<post<<endl;
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
    
    iterativePreInPost(root);
        
    return 0;
}