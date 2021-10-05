#include<iostream>
#include<string>
#include<stack>
using namespace std;

int precedence(char oprtr)
{
    if(oprtr == '+'){
        return 1;
    }
    else if(oprtr == '-'){
        return 1;
    }
    else if(oprtr == '*'){
        return 2;
    }
    else{
        // for '/'
        return 2;
    }
}

int operation(int x, int y, char oprtr)
{
    if(oprtr == '+'){
        return x+y;
    }
    else if(oprtr == '-'){
        return x-y;
    }
    else if(oprtr == '*'){
        return x*y;
    }
    else{
        // for '/'
        return x/y;
    }
}


int main()
{
    string str;
    
    // Read the string input UNTIL A NEW LINE is encountered, (i.e include spaces in str)
    getline(cin, str, '\n');
    
    stack <char> oprtr;
    stack <int> oprnd;
    
    for(int i = 0; i < str.size(); i++){
        char ch = str[i];
        
        if(ch == '('){
            oprtr.push(ch);
        }
        
        else if(ch == ')'){
            while(!oprtr.empty() && oprtr.top() != '('){
                
                int op2 = oprnd.top();
                oprnd.pop();
                int op1 = oprnd.top();
                oprnd.pop();
                char op = oprtr.top();
                oprtr.pop();
                
                int val = operation(op1, op2, op);
                // cout<<"1 "<<op1<<" "<<op<<" "<<op2<<" "<<val<<endl;
                
                // push back the result into operand stack
                oprnd.push(val);
            }
            
            // pop the '(' as well
            if(!oprtr.empty())
                oprtr.pop();
        }
        
        else if(ch == '+' || ch == '-' || ch == '*' || ch == '/'){
            // Pop wile:
            // 1> st.top() != '('  <2> st.top() precedence is >= ch  <3> !st.empty()
            while(!oprtr.empty() && oprtr.top() != '(' 
            && precedence(ch) <= precedence(oprtr.top())){
                
                int op2 = oprnd.top();
                oprnd.pop();
                int op1 = oprnd.top();
                oprnd.pop();
                char op = oprtr.top();
                oprtr.pop();
                
                int val = operation(op1, op2, op);
                // cout<<"2 "<<op1<<" "<<op<<" "<<op2<<" "<<val<<endl;                
                
                // push the value calculated into operand stack
                oprnd.push(val);
                
            }
            
            // at last, push the current char into the oprtr stack
            oprtr.push(ch);
        }
        
        // do this to check if character is a number and not a space (or anything else)
        else if(isalnum(ch)){
            // operand
            oprnd.push(ch - '0');   // push the corresponding integer
        }
    }
    
    // pop all the oprtr elements
    while(!oprtr.empty()){
        int op2 = oprnd.top();
        oprnd.pop();
        int op1 = oprnd.top();
        oprnd.pop();
        char op = oprtr.top();
        oprtr.pop();
        
        int val = operation(op1, op2, op);
        // cout<<"3 "<<op1<<" "<<op<<" "<<op2<<" "<<val<<endl;
        
        oprnd.push(val);
    }
    
    cout<<oprnd.top();
    
    return 0;
}