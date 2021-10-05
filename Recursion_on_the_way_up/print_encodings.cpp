#include <iostream>
#include<string>
using namespace std;

void printEncoding(string str, string asf){
    // Base case
    if(str.size() == 0){
        cout<<asf<<endl;
        return;
    }
    
    // check if single character
    if(str.size() == 1){
        
        // if '0' -> return 
        if(str[0] == '0')
            return;
        
        // else, make the char as integer
        int intCode = str[0] - '0';
        // get the character corresponding to the integer code (typecast into char)
        char charCode = (char) ('a' + intCode - 1);
        
        // make the recursive call by appending it to asf or simply print as str.size() == 1
        printEncoding(str.substr(1), asf + charCode);
        
    } // else if size >= 2
    else{
        
        // if '0' -> return 
        if(str[0] == '0')
            return;
        
        // append the char code corresponding to FIRST CHAR and make call for remaining str
        int intCode = str[0] - '0';
        char charCode = (char) ('a' + intCode - 1);
        printEncoding(str.substr(1), asf + charCode);
        
        // append the char code corresponding to FIRST TWO CHAR and make the call for remaining str
        string ch2 = str.substr(0, 2);
        
        // convert this string of length 2 into integer. Note that -'0' works with single character
        intCode = stoi(ch2);
        
        // check if intCode <= 26
        if(intCode <= 26){
            charCode = (char) ('a' + intCode - 1);
            printEncoding(str.substr(2), asf + charCode);
        }
        
    }
}

int main(){
    string str;
    cin>>str;
    printEncoding(str,"");
    
}