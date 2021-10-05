#include<iostream>
#include<string>
#include<stack>
using namespace std;

int precedence(char ch)
{
    if(ch == '+' || ch == '-'){
        return 1;
    }
    else if(ch == '*' || ch == '/'){
        return 2;
    }
}

int main()
{
    string infix;
    getline(cin, infix, '\n');
    
    stack <string> pre;
    stack <string> post;
    stack <char> op;
    
    for(int i = 0; i < infix.size(); i++){
        char ch = infix[i];
        
        if(ch == '('){
            op.push(ch);
        }
        
        else if(ch == ')'){
            while(!op.empty() && op.top() != '('){
                
                char oprtr = op.top();
                
                // prefix
                string v2 = pre.top();
                pre.pop();
                string v1 = pre.top();
                pre.pop();
                string res = oprtr + v1 + v2;
                pre.push(res);
                
                // postfix
                v2 = post.top();
                post.pop();
                v1 = post.top();
                post.pop();
                res = v1 + v2 + oprtr;
                post.push(res);
                
                op.pop();
                
            }
            // pop '(' as well
            op.pop();
        }
        
        else if(ch == '+' || ch == '-' || ch == '*' || ch == '/'){
            while(!op.empty() && op.top() != '(' 
                   && precedence(ch) <= precedence(op.top())){
                
                char oprtr = op.top();
                
                // prefix
                string v2 = pre.top();
                pre.pop();
                string v1 = pre.top();
                pre.pop();
                string res = oprtr + v1 + v2;
                pre.push(res);
                
                // postfix
                v2 = post.top();
                post.pop();
                v1 = post.top();
                post.pop();
                res = v1 + v2 + oprtr;
                post.push(res);

                op.pop();
                
            }
            // push the current ch into the op stack
            op.push(ch);
        }
        
        else if(ch >= '0' && ch <= '9' || ch >= 'a' && ch <= 'z' ||
                ch >= 'A' && ch <= 'Z'){
                    
                    //NOTE: ch is a character and stacks are of type string
                    // So, convert ch to string 
                    string str;
                    str += ch;  // += is overloaded to make char to string
                    pre.push(str);
                    post.push(str);
        }
        
    }
    
    // Pop out the remaining operators
    while(!op.empty()){
        
        char oprtr = op.top();
        
        // prefix
        string v2 = pre.top();
        pre.pop();
        string v1 = pre.top();
        pre.pop();
        string res = oprtr + v1 + v2;
        pre.push(res);

        // postfix
        v2 = post.top();
        post.pop();
        v1 = post.top();
        post.pop();
        res = v1 + v2 + oprtr;
        post.push(res);

        op.pop();
    }
    
    cout<<post.top()<<endl;
    cout<<pre.top()<<endl;
    
    return 0;
}