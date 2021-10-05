#include<iostream>
#include<unordered_set>
using namespace std;

void getCommonElements(int *arr1, int *arr2, int n1, int n2)
{
    unordered_set <int> hash;
    
    for(int i = 0; i < n1; i++){
        hash.insert(arr1[i]);
    }
    
    // for(auto it : hash){
    //     cout<<it<<endl;
    // }
    
    // for(auto itr = hash.begin(); itr != hash.end(); itr++){
    //     cout<<*itr<<endl;
    // }
    
    for(int i = 0; i < n2; i++){
        if(hash.find(arr2[i]) != hash.end()){
            cout<<arr2[i]<<endl;
            // remove it from hash to not print the duplicates
            hash.erase(arr2[i]);
        }
    }
}

int main()
{
    int n1, n2;
    
    cin>>n1;
    int arr1[n1];
    for(int i = 0; i < n1; i++){
        cin>>arr1[i];
    }
    
    cin>>n2;
    int arr2[n2];
    for(int i = 0; i < n2; i++){
        cin>>arr2[i];
    }
    
    getCommonElements(arr1, arr2, n1, n2);
    
    return 0;
}