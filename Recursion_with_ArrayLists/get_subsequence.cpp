#include <iostream>
#include <vector>
using namespace std;

vector<string> gss(string s){
    
    if(s.size() == 0){
        // create a vector of string and push an empty string
        vector <string> res;
        res.push_back("");
        return res;
    }
    
    // get the first character of the string
    char firstChar = s[0];
    
    // call the gss recursively with the remaining substring and store the returned result in a vector
    string remainingString = s.substr(1);
    vector <string>  res = gss(remainingString);
    
    // DECLARE A NEW VECTOR TO STRORE THE FINAL RESULT
    vector <string> ans;
    
    // loop through the res VECTOR (NOT "ans" VECTOR)-> append "" in beginning of each string in "res" & push subsequence in "ans" 
    for(string i : res){
        ans.push_back("" + i);
    }
    
    // push the subsequence with first char at the beginning
    for(string i : res){
        ans.push_back(firstChar + i);
    }
    
    return ans;
    
}

int main(){
    string s;
    cin >> s;
    vector<string> ans = gss(s);
    int cnt = 0;

    cout << '[';
    for (string str : ans){
        if (cnt != ans.size() - 1)
            cout << str << ", ";
        else
            cout << str;
        cnt++;
    }
    cout << ']';
}