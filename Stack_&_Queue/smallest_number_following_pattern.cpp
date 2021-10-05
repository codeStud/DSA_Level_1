#include<iostream>
#include<stack>
#include<string>
using namespace std;

int main()
{
    string str;
    cin>>str;
    
    stack <int> st;
    int num = 1;
    
    for(int i = 0; i < str.size(); i++){
        char ch = str[i];
        
        if(ch == 'd'){
            // push the num
            st.push(num);
            // increment the num
            num++;
        }
        
        else if(ch == 'i'){
            // push the num
            st.push(num);
            // increment the num
            num++;
            
            // print all the elements in stack after pop
            while(!st.empty()){
                cout<<st.top();
                st.pop();
            }
        }
    }
    
    // To understand the below logic, trace it for a single input i.e 'd' or 'i'
    
    // push the last num
    st.push(num);
    
    // if there are elements remaining in stack, pop and print them
    while(!st.empty()){
        cout<<st.top();
        st.pop();
    }
    
    return 0;
}