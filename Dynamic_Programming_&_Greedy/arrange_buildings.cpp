#include<iostream>
using namespace std;

int main()
{
    int n;
    cin>>n;
    
    // No. of plots of length 1 having space in it = 1 i.e "space"
    long prevSpace = 1;
    
    // No. of plots of length 1 having building in it = 1 i.e "building"
    long prevBuilding = 1;
    
    // making plots of length 2 to n using prevSpace and prevBuilding
    for(int i = 2; i <= n; i++){
        
        // simply add a 'space' in the prevSpace and prevBuilding to get the total 'i' length plots following the rule
        long newSpace = prevSpace + prevBuilding;
        
        // to avoid having two buildings side by side, you can add a building in front of the prevSpace
        long newBuilding = prevSpace;
        
        // move the prev variables forward
        prevSpace = newSpace;
        prevBuilding = newBuilding;
        
    }
    
    long total = prevBuilding + prevSpace;
    
    // Since there are two lanes and road in the middle, for each combination of space and building in the plot on one side, 
    // there will be 'total' number of combinations on the other side of the road. So, total possible combinations would be total * total
    
    cout<<total*total;
    
    return 0;
}