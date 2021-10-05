#include <iostream>
using namespace std;

void printPermutations(string str, string asf){
    // Base Case
    if(str.size() == 0){
        cout<<asf<<endl;
        return;
    }
    
    // take chars from str one by one -> append it to your answer -> make recursive call after removing this character from str
    for(int i = 0; i < str.size(); i++){
        char ch = str[i];
        
        // extract left part of the str
        // str.substr(start index, length)
        string leftStr = str.substr(0, i);
        
        // extract the right part of str
        string rightStr = str.substr(i+1);
        
        // form a new string to make the recursive call
        string newStr = leftStr + rightStr;
        
        printPermutations(newStr, asf + ch);
        
    }

    
}

int main(){
    string str;
    cin>>str;
    printPermutations(str,"");
    
}