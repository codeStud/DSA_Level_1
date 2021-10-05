#include <iostream>
using namespace std;

string codes[] = {".;", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tu", "vwx", "yz"};

void printKPC(string ques, string asf){
    // when ques size becomes 0, simply print the asf
    if(ques.size() == 0){
        cout<<asf<<endl;
        return;
    }
    
    // remove the first char from ques
    char firstChar = ques[0];
    
    // get the remaining ques (i.e remaining keypad combination)
    string remainingKPC = ques.substr(1);
    
    // Loop through all the characters at the number 'firstChar' and make calls by appending
    // one character at a time to the asf
    for(char i : codes[firstChar - '0']){   // -'0' to convert index to int
        printKPC(remainingKPC, asf + i);
    }
    
}

int main(){
    string str;
    cin >> str;
    printKPC(str, "");
}