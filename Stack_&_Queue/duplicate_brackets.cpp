#include<iostream>
#include<stack>
#include<string>
using namespace std;

int main()
{
    string str;
    
    // cin reads word by word and treats " " as a delimeter. But here you want '\n' as
    // delimiter. Thus use getline().
    // NOTE: 3rd parameter to getline should be a character & not string. So, "\n" wud be wrong!!
    getline(cin, str, '\n');

    stack <char> st;

    for(char ch : str){
        if(ch == ')'){
            // if stack top contains an '(' without having any other character, that means this is a duplicate bracket.
            if(st.top() == '('){
                cout<<"true";
                return 0;
            }
            // else, keep popping until you find a '('
            else{
                while(st.top() != '('){
                    st.pop();
                }
                // pop the matching '('
                st.pop();
            }
        }
        
        // keep pushing everything else
        else{
            st.push(ch);
        }
    }
    
    // print false if you are out of all the loops
    cout<<"false";
    
    return 0;
}