#include <iostream>
using namespace std;

void printSS(string ques, string ans){
    // Base case
    if(ques.size() == 0){
        cout<<ans<<endl;
        return;
    }
    
    char firstChar = ques[0];
    string restOfQues = ques.substr(1);
    
    printSS(restOfQues, ans + firstChar);
    printSS(restOfQues, ans);
    
    return;
}

int main(){
    string str;
    cin >> str;
    printSS(str, "");
}