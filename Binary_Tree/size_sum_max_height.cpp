#include<iostream>
#include<string>
#include<stack>
#include<climits>
#include<utility>
#include<algorithm>
using namespace std;

// You could have created "struct node" and "getNode()" in place of the class Node
class Node{
    public:
        int data;
        Node* left;
        Node* right;
        
        Node(int data, Node* left, Node* right)
        {
            this->data = data;
            this->left = left;
            this->right = right;
        }
};


Node* construct(int *arr, int n)
{
    Node* root = new Node(arr[0], NULL, NULL);
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
                // create the left node of the node at stack top. Since, first element of pair is a pointer, adding child to the topPair variable
                // will also reflect in the stack.
                topPair.first->left = new Node(arr[idx], NULL, NULL);
                
                // create pair of the newly created node
                pair <Node*, int> leftPair = make_pair(topPair.first->left, 1);
                
                // topPair is the local variable and writing topPair.second++ won't change the value of this pair in the stack. So, change it 
                // like this. (Before pushing the newly created node)
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
                // will also reflect in the stack.
                topPair.first->right = new Node(arr[idx], NULL, NULL);
                
                pair <Node*, int> rightPair = make_pair(topPair.first->right, 1);
                
                // topPair is the local variable and writing topPair.second++ won't change the value of this pair in the stack. So, change it 
                // like this. (Before pushing the newly created node)
                st.top().second++;              
                
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


int size(Node* root)
{
    if(root == NULL){
        return 0;
    }
    
    int leftSize = size(root->left);
    int rightSize = size(root->right);
    
    return leftSize + rightSize + 1;
}


int sum(Node* root)
{
    if(root == NULL){
        return 0;
    }
    
    int leftSum = sum(root->left);
    int rightSum = sum(root->right);
    
    return leftSum + rightSum + root->data;
}


int maxVal(Node* root)
{
    if(root == NULL){
        return INT_MIN;
    }
    
    int leftMax = maxVal(root->left);
    int rightMax = maxVal(root->right);
    
    return max({leftMax, rightMax, root->data});
}


int height(Node* root)
{
    if(root == NULL){
        return -1;
    }
    
    int leftHeight = height(root->left);
    int rightHeight = height(root->right);
    
    return max(leftHeight, rightHeight) + 1;
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
    
    cout<<size(root)<<endl;
    cout<<sum(root)<<endl;
    cout<<maxVal(root)<<endl;
    cout<<height(root)<<endl;
    
    return 0;
}