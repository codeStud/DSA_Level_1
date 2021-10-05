#include<iostream>
#include<string>
#include<vector>
using namespace std;

vector<string> getPaths(int n)
{
    if(n == 0){
        vector <string> temp;
        // 1 path to go from 0 to 0, i.e NULL path (stand there itself) => push_back("")
        temp.push_back("");
        return temp;
    }
    else if(n < 0){
        // declare an empty vector since you've to return a vector as per the function definition
        vector <string> temp;
        // simply return without pushing anything bcz no possible path
        return temp;
    }
    
    vector <string> oneStep = getPaths(n-1);
    vector <string> twoStep = getPaths(n-2);
    vector <string> threeStep = getPaths(n-3);
    
    // declare a vector of strings for final answer
    vector <string> ans;
    
    // append '1' in front of oneStep vector to get paths starting with 1
    for(string i : oneStep)
        ans.push_back('1' + i);
        
    // append '2' in front of twoStep vector to get paths starting with 2
    for(string i : twoStep)
        ans.push_back('2' + i);
        
    // append '3' in front of threeStep vector to get the paths starting from 3
    for(string i : threeStep)
        ans.push_back('3' + i);
        
    return ans;
}

int main()
{
    int n;
    cin>>n;
    
    vector <string> ans = getPaths(n);
    
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