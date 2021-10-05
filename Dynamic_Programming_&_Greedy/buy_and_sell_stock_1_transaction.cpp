#include<iostream>
#include<climits>
using namespace std;

int main()
{
    int n;
    cin>>n;
    
    int prices[n];
    for(int i = 0; i < n; i++){
        cin>>prices[i];
    }
    
    int leastSoFar = INT_MAX;
    int maxProfitToday = 0;
    int maxProfit = 0;
    
    for(int i = 0; i < n ; i++){
        // maintain leastSo far
        if(prices[i] < leastSoFar){
            leastSoFar = prices[i];
        }
        
        // Calculate the today's max profit
        maxProfitToday = prices[i] - leastSoFar;
        
        // Keep track of the maxProfit
        if(maxProfitToday > maxProfit){
            maxProfit = maxProfitToday;
        }
        
    }
    
    cout<<maxProfit;
    
    return 0;
}