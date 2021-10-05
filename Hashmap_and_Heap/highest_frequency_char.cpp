#include<iostream>
#include<string>
#include<unordered_map>
#include<climits>
using namespace std;

int main()
{
    string str;
    getline(cin, str);
    
    unordered_map <char, int> hashMap;
    
    for(char ch : str){
        hashMap[ch]++;
    }
    
    // for(auto x : hashMap){
    //     cout<<x.first<<" "<<x.second<<endl;
    // }
    
    int maxCount = INT_MIN;
    char ch;
    for(auto itr = hashMap.begin(); itr != hashMap.end(); itr++){
        if(itr->second > maxCount){
            maxCount = itr->second;
            ch = itr->first;
        }
    }     
    
    cout<<ch<<endl;
    
    return 0;
}