// Everyday is a potential buying day or selling day. 
// Also, since NO Overlapping transaction => for all the possible transactions, on any "i"-th day, you can be in two state:
// state-1: You've a SINGLE stock remaining to be sold.
// state-2: You've sold all the stocks & aren't holding any stock.
// So, for each day, calculate the maximum profit in both states => ON THE LAST DAY, you'll have max profit in selling state (i.e Have sold all the stocks)

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
    
    int fee;
    cin>>fee;
    
    int oldBuyProfit = -prices[0];
    int oldSellProfit = 0;

    for(int i = 1; i < n; i++){
        int newBuyProfit = 0;
        int newSellProfit = 0;

        // Each day, 2 choices - a> Buy  b> Sell
        
        // FOR BUYING: Can buy if sold previously (bcz no overlapping transaction) + buy only if oldSellProfit - today's price > oldBuyProfit 
        if(oldSellProfit - prices[i] > oldBuyProfit){
           newBuyProfit = oldSellProfit - prices[i]; 
        }
        // else don't buy today. Continue with previous buying state profit
        else{
            newBuyProfit = oldBuyProfit;
        }
        
        // FOR SELLING: Can sell only if previously bought + sell only if newSellProfit is more than oldSellProfit
        if(oldBuyProfit + (prices[i] - fee) > oldSellProfit){
            newSellProfit = oldBuyProfit + prices[i] - fee;
        }
        // else, don't sell today. Continue you old selling profit
        else{
            newSellProfit = oldSellProfit;
        }
        
        // For the next iteration, move the old variables ahead
        oldBuyProfit = newBuyProfit;
        oldSellProfit = newSellProfit;
    }
    
    // Max profit will be after selling at last
    cout<<oldSellProfit;
    
    return 0;
}