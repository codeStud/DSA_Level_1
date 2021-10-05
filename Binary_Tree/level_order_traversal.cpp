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
    Node* root = getNode(arr[0]);
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


void levelOrder(Node *root)
{
    queue <Node*> q;
    q.push(root);
    
    while(!q.empty()){
        int n = q.size();
        
        for(int i = 0; i < n; i++){
            // remove
            Node *temp = q.front();
            q.pop();
            
            // print
            cout<<temp->data<<" ";
            
            // add children
            if(temp->left){
                q.push(temp->left);
            }
            
            if(temp->right){
                q.push(temp->right);
            }
        }
        
        cout<<endl;
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
    
   levelOrder(root);
    
    return 0;
}