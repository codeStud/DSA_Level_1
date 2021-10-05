#include<iostream>
#include<string>
#include<stack>
using namespace std;

int main()
{
    string str;
    // cin reads word by word and treats " " as a delimeter. But here you want '\n' as
    // delimiter. Thus use getline().
    // NOTE: 3rd parameter to getline should be a character & not string. So, "\n" wud be wrong!!
    getline(cin, str, '\n');
    
    stack <int> st;

    for(int i = 0; i < str.size(); i++){
        // Push if closing bracket
        if(str[i] == '(' || str[i] == '[' || str[i] == '{'){
            st.push(str[i]);
        }
        // Pop if closing bracket. Ignore the rest 
        else{
            if(str[i] == ')'){
                if(st.empty() || st.top() != '('){
                    cout<<"false";
                    return 0;
                }
                else{
                    st.pop();
                }
            }
            else if(str[i] == '}'){
                if(st.empty() || st.top() != '{'){
                    cout<<"false";
                    return 0;
                }
                else{
                    st.pop();
                }
            }
            else if(str[i] == ']'){
                if(st.empty() || st.top() != '['){
                    cout<<"false";
                    return 0;
                }
                else{
                    st.pop();
                }
            }
        }
    }
    
    // check if stack is empty or not at last
    if(st.empty()){
        cout<<"true";
    }
    else{
        cout<<"false";
    }
    
    return 0;
}