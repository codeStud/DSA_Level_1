#include<iostream>
#include<cstring>
using namespace std;

int main()
{
    string str;
    cin>>str;
    
    // count of subsequences of form a+
    int a = 0;
    
    // count of subsequences of form a+b+
    int ab = 0;
    
    // count of subsequences of form a+b+c+
    int abc = 0;
    
    for(char ch : str){
        // if ch = 'a' then it can either attach to previous 'a' subsequence or doesn't attach => 2*a (a is the count of previous a+ subsequence). 
        // Also, this current ch = 'a' can drop everything previous and start a new subsequence with 'a'. Thus, formula for a+ subsequence count is 2*a + 1
        if(ch == 'a'){
            a = 2*a + 1;
        }
        
        // if ch = 'b' then it can either get attach to previous 'ab' subsequence or doesn't => 2*ab (ab is the count of previous a+b+ subsequence). 
        // Also, this current ch = 'b' will attach with previous 'a' subsequence to give rise to a new 'a+b+' subsequence. 
        // Thus, formula for a+b+ subsequence count is 2*ab + a
        else if(ch == 'b'){
            ab = 2 * ab + a;
        }
        
        // if ch = 'c' then it can get attach to previous 'a+b+c+' subsequence or won't => 2*abc. 
        // Then, it will get attached to previous 'a+b+' subsequence to give rise to a new 'a+b+c+' subsequence.
        else if(ch == 'c'){
            abc = 2 * abc + ab;
        }
        
    }
    
    cout<<abc;
    
    return 0;
}