#include <iostream>
#include<vector>
using namespace std;

int csTabulation(int n, int *memo)
{
    memo[0] = 1;
    
    for(int i = 1; i <= n; i++){
        if(i == 1){
            memo[i] = memo[i-1];
        }
        
        else if(i == 2){
            memo[i] = memo[i-1] + memo[i-2];
        }
        
        else{
            memo[i] = memo[i-1] + memo[i-2] + memo[i-3];
        }
    }
    
    // memo[n] = 1;
    // memo[n-1] = memo[n];
    // memo[n-2] = memo[n] + memo[n-1];
    
    // for(int i = n-3; i >= 0; i--){
    //     memo[i] = memo[i + 1] + memo[i + 2] + memo[i + 3];
    // }
    
    return memo[n];
}

int cs(int n, int *memo){
    if(n < 0){
        return 0;
    }
    
    if(n == 0){
        return 1;
    }
    
    if(memo[n] > 0){
        return memo[n];
    }

    int oneStep = cs(n - 1, memo);
    int twoStep = cs(n - 2, memo);
    int threeStep = cs(n - 3, memo);
    
    int totalPaths = oneStep + twoStep + threeStep;
    
    memo[n] = totalPaths;
    return memo[n];

}

int main(){
    int n;
    cin>>n;
    int cache[n+1] = {0};
    cout<<cs(n, cache)<<endl;
    // cout<<csTabulation(n, cache)<<endl;
}