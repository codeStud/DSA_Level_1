// Everyday is a potential buying day, selling day or cooldown day. 
// Also, since NO Overlapping transaction => for all the possible transactions, on any "i"-th day, you can be in 3 state:
// state-1: You've a SINGLE stock remaining to be sold.
// state-2: You've sold all the stocks & aren't holding any stock.
// state-3: (Cooldown day, i.e you've sold on the previous day and AREN'T holding any stock => ready to buy on next day)
// So, for each day, calculate the maximum profit in all states => ON THE LAST DAY, you'll have max profit in selling state (i.e Have sold all the stocks)

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
    
    int oldBuyProfit = -prices[0];
    int oldSellProfit = 0;
    int oldCooldownProfit = 0;
    
    for(int i = 1; i < n; i++){
        int newBuyProfit = 0;
        int newSellProfit = 0;
        int newCooldownProfit = 0;
        
        // Each day, 3 choices - a> Buy  b> Sell  c> Cooldown
        
        // FOR BUYING: Can buy only if previously it was a cooldown + buy only if newBuyProfit is more than oldBuyProfit
        if(oldCooldownProfit - prices[i] > oldBuyProfit){
           newBuyProfit = oldCooldownProfit - prices[i]; 
        }
        else{
            newBuyProfit = oldBuyProfit;
        }
        
        // FOR SELLING: Can sell only if previously bought + sell only if newSellProfit is more than oldSellProfit
        if(oldBuyProfit + prices[i] > oldSellProfit){
            newSellProfit = oldBuyProfit + prices[i];
        }
        else{
            newSellProfit = oldSellProfit;
        }
        
        // FOR COOLDOWN: Can cooldown only if previously sold + cooldown only if newCooldownProfit is more than oldCooldownProfit
        if(oldSellProfit > oldCooldownProfit){
            newCooldownProfit = oldSellProfit;
        }
        else{
            newCooldownProfit = oldCooldownProfit;
        }
        
        // For the next iteration, move the old variables ahead
        oldBuyProfit = newBuyProfit;
        oldSellProfit = newSellProfit;
        oldCooldownProfit = newCooldownProfit;
        
    }
    
    // Max profit will be after selling at last
    cout<<oldSellProfit;
    
    return 0;
}