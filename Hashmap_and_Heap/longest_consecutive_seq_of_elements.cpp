#include<iostream>
#include<unordered_set>
using namespace std;

void longestConsecutiveSeq(int *arr, int n)
{
    
    // CAN USE MAP in place of two set
    unordered_set <int> hash;
    unordered_set <int> arrElements;
    
    // push the arr elements
    for(int i = 0; i < n; i++){
        hash.insert(arr[i]);
        arrElements.insert(arr[i]);
    }
    
    // Loop throught the ARRAY and check if the current element could be the starting 
    // point of a consecutive seq. If not, erase it from hash
    for(int i = 0; i < n; i++){
        // if 'number' prev to current arr[i] => arr[i] can't be starting point
        if(hash.find(arr[i] - 1) != hash.end()){
            hash.erase(arr[i]);
        }
    }
    
    // Now we have only the starting numbers of every sequence in the "hash".
    // Find the max length seq and print it.
    
    int start = -1;
    int maxLen = -1;
    for(int i = 0; i < n; i++){
        int curStart = arr[i];
        int curLen = 1;
        
        // if current element is the starting point of some sequence        
        if(hash.find(curStart) != hash.end()){
            int temp = curStart;
            
        // check if the consecutive elements starting from curStart exist in arrElements
            while(arrElements.find(temp + 1) != arrElements.end()){
                curLen += 1;
                temp = temp + 1;
            }
        
            if(curLen >= maxLen){
                // if equal, then start from the lesser starting number 
                if(curLen == maxLen){
                    start = min(curStart, start);
                }
                else{
                    maxLen = curLen;
                    start = curStart;
                }
            }
            
        }
        
    }
    
    // print the longest found consecutive sequence
    for(int i = 0; i < maxLen; i++){
        cout<<start + i<<endl;
    }
}


int main()
{
    int n;
    
    cin>>n;
    int arr[n];
    for(int i = 0; i < n; i++){
        cin>>arr[i];
    }
    
    longestConsecutiveSeq(arr, n);
    
    return 0;
}