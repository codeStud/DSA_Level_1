#include<iostream>
using namespace std;

int main()
{
    int n,k;
    cin>>n>>k;
    
    // since k colors => k ways to color the 1st fence
    
    // Now for 2nd fence
    
    // No. of ways such that fence 1 & 2 have same color = whatever color is on previous fence, put the same color. So, 1 choice (same color) for each of the 'k' colors
    long sameColor = k * 1;
    
    // No. of ways such that fence 1 & 2 have different color = whatever color is on previous fence, put any different color on current fence. So, k-1 choices for each of the 'k' colors of prev fence.
    long diffColor = k * (k-1);
    
    // sum of last two fence (prev and current fence) having same color & last two fence have diff color
    // total no. of ways to paint fences without violating the rule
    long total = sameColor + diffColor;
    
    // from fence 3 TILL nth FENCE (<=)
    for(int i = 3; i <= n; i++){
        // to make last 2 fence same color => 1 choice (same color as previous fence for the ith gate) for each of the diffColor count of previous fence.
        sameColor = diffColor * 1;
        
        // to make last 2 fence diff color => k-1 choice ( diff color than that previous fence) for total color combinations of the previous fence.
        diffColor = total * (k-1);
        
        // take the total
        total = sameColor + diffColor;
    }
    
    cout<<total;
    
    return 0;
}