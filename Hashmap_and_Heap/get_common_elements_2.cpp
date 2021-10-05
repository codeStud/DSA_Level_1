#include<iostream>
#include<unordered_map>
using namespace std;

void getCommonElements(int *arr1, int *arr2, int n1, int n2)
{
    unordered_map<int, int> map;
    
    for(int i = 0; i < n1; i++){
        // key = arr1[i]  & value = count of arr1[i]
        map[arr1[i]]++;
    }
    
    for(int i = 0; i < n2; i++){
        // if the element is found, print it and decrease it's count (until 0)
        if(map.find(arr2[i]) != map.end() && map[arr2[i]] != 0){
            cout<<arr2[i]<<endl;
            map[arr2[i]]--;
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