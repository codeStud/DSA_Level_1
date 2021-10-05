#include<iostream>
#include<vector>
#include<string>
using namespace std;

vector <string> codes = {".;", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tu", "vwx", "yz"};

vector<string> getKPC(string s)
{
    // base case
    if(s.size() == 0){
        vector <string> res;
        res.push_back("");
        return res;
    }
    
    // remove the first character
    char firstChar = s[0];
    
    // get the remaining string
    string remainingString = s.substr(1);
    
    // make recursive call with the remaining substring and store the result in a vector
    vector <string> res = getKPC(remainingString);
    
    // DECLARE A VECTOR TO STORE THE FINAL RESULT
    vector <string> ans;
    
    // Get the keypad combination corr. to the firstChar. But first, don't forget to convert firstChar to corresponding integer value i.e for eg - '5' to 5 (subtract '0')
    string keypadComb = codes[firstChar - '0'];
    
    // loop through this keypadComb and append each character to the string received in "res" and push the final string to the ans
    
    for(char i : keypadComb){
        for(string st : res){
            ans.push_back(i + st);
        }
    }
    
    return ans;
}

int main()
{
    string s;
    cin>>s;
    
    vector <string> ans = getKPC(s);
    
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
    
    return 0;
}