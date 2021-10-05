#include<iostream>
#include<cstring>
using namespace std;

int main()
{
    string str;
    cin>>str;
    
    int dp[str.size()];
    dp[0] = 1;
    
    for(int i = 1; i < str.size(); i++){
        // case1: prevChar == '0' && currentChar == '0'
        if(str[i] == '0' && str[i-1] == '0'){
            dp[i] = 0;
        }
        
        // case2: prevChar == '0' && currentChar is non-zero
        else if(str[i-1] == '0' && str[i] != '0'){
            // can only include 'i'th character as a single character eg - "205", here when at '5', it can be treated only as '20' & '5' and not '2' & '05'
            dp[i] = dp[i-1];
        }
        
        // case3: prevChar != '0' && currentChar == '0'
        else if(str[i-1] != '0' && str[i] == '0'){
            // can't treat current 'i'th character as a single character but can also combine it with prevChar 
            // eg - '220', here when at '0', you can't include '0' but can treat it like '20' (<=26)
            if(stoi(str.substr(i-1, 2)) <= 26){
                dp[i] = (i >= 2 ? dp[i-2] : 1);
            }
            else{
                dp[i] = 0;
            }
            
        }
        
        //case4: prevChar != '0' && currentChar != '0'
        else{
            // DON'T FORGET TO CHECKOUT HOW SUBSTR WORKS
            if(stoi(str.substr(i-1, 2)) <= 26){
                dp[i] = dp[i-1] + (i >= 2 ? dp[i-2] : 1);
            }
            else{
                dp[i] = dp[i-1];
            }
        }
    }
    
    cout<<dp[str.size()-1];
    
    return 0;
}