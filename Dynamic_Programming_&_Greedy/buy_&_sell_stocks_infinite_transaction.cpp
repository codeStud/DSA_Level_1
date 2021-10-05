#include<iostream>
using namespace std;

int main()
{
    int n;
    cin>>n;
    
    int prices[n];
    for(int i = 0; i < n; i++){
        cin>>prices[i];
    }
    
    int buyPrice = 0;   // keep it at the first index of prices initially
    int sellPrice = 0;  // Keep it at the first index of the prices initially
    int profit = 0;
    
    for(int i = 1; i < n; i++){
        // if the price is going up, the keep moving ONLY the selling price index
        if(prices[i] >= prices[i-1]){
            sellPrice = i;
        }
        // if price goes down, collect the previous profit and move both buyPrice and sellPrice forward
        else{
            profit += prices[sellPrice] - prices[buyPrice];
            buyPrice = sellPrice = i;
        }
        
    }
    
    // If last value or prices is also higher than 2nd last price => we need to collect this profit as well. 
    // prices[sellPrice] - prices[buyPrice] = 0 if there is a dip in the sales graph since in case of dip, buyPrice = sellPrice = i; 
    profit += prices[sellPrice] - prices[buyPrice];
    
    cout<<profit;
    
    return 0;
}