#include<iostream>
#include<algorithm>
#include<vector>
#include<stack>
using namespace std;

int main()
{
    int n;
    cin>>n;
    
    // taking input in vector of pairs so that we can sort it later by start-time
    vector<pair<int, int>> timing;
    for(int i = 0; i < n; i++){
        int a, b;
        cin>>a>>b;
        timing.push_back(make_pair(a, b));
    }
    
    
    // Sort by start time 
    //  By default, sort fnctn sorts vector elements on basis of first element of pairs.
    
    sort(timing.begin(), timing.end());
    
    stack <pair<int, int>> st;
    
    // push first pair after sorting into stack
    st.push(timing[0]);
    
    for(int i = 1; i < n; i++){
        
        // if the end-time of st.top() >= start time of the current pair => MERGE
        if(st.top().second >= timing[i].first){
           
            // update end-time of temp to the max of both end times
            st.top().second = max(st.top().second, timing[i].second);
        }
        
        else{
            // can't be merged => simply push it to stack
            st.push(timing[i]);
        }
        
    }
    
    // to print it in the ascending order, push it back to another stack
    stack <pair<int, int>> st2;
    while(!st.empty()){
        st2.push(st.top());
        st.pop();
    }
    
    // Now, print in ascending order of the timings
    while(!st2.empty()){
        cout<<st2.top().first<<" "<<st2.top().second<<endl;
        st2.pop();
    }
    
    return 0;
    
}