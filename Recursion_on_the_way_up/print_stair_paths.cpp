#include <iostream>
using namespace std;

void printStairPaths(int n, string psf){
    // when n becomes 0, print the path 
    if(n == 0){
        cout<<psf<<endl;
        return;
    }
    
    // call the function recursively by first taking 1 step and then appending it to the psf
    printStairPaths(n-1, psf + '1');
    
    // call for 2 step
    if(n >= 2)
        printStairPaths(n-2, psf + '2');
    
    // call for 3 step
    if(n >= 3)
        printStairPaths(n-3, psf + '3');
    
}

int main(){

    int n;
    cin >> n;
    printStairPaths(n, "");
}