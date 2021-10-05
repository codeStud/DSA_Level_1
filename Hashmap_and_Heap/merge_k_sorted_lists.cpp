#include<iostream>
#include<queue>
#include<vector>
using namespace std;

class Pair {
    public:
        int listIndex;
        int dataIndex;
        int val;
    
    Pair(int li, int di, int v)
    {
        this->listIndex = li;
        this->dataIndex = di;
        this->val = v;
    }
};

// we are doing operator overloading through this
bool operator < (const Pair& p1, const Pair& p2)
{
 
    // this will return true when second Pair
    // has lesser Value. Suppose we have p1.val=5
    // and p2.val=10 then the object which
    // have min val will be at the top(Min Heap)
    return p1.val > p2.val;
}


vector<int> merge_K_sorted_lists(vector<vector<int>>& lists)
{
    vector <int> res;
    
    // We've done operator overloading of "<" which will return the element with the minimum val (Min Heap). 
    // So, NO NEED to write a comparable function separately or to declare pq as - priority_queue <Pair, vector<Pair>, comparable> pq;
    
    // Priority Queue of Pair class.
    priority_queue <Pair> pq;
    
    // add first element (dataIndex = 0) of each list to the priority_queue
    for(int i = 0; i < lists.size(); i++){
        Pair p(i, 0, lists[i][0]);
        pq.push(p);
    }
    
    while(!pq.empty()){
        // get the element with minimum value
        Pair p = pq.top();
        pq.pop();
        
        // add it to the final result list
        res.push_back(p.val);
        
        // go to the next element of the SAME list (p.listIndex)
        p.dataIndex++;
        
        // if this dataIndex is a valid index in the current list at p.listIndex
        if(p.dataIndex < lists[p.listIndex].size()){
            
            // simple change the val of Pair p (listIndex is same & dataIndex is pointing to next element in the same list from which p.val was removed)
            p.val = lists[p.listIndex][p.dataIndex];
            
            // push the UPDATED (Not new) pair to priority_queue
            pq.push(p);
        }
        
    }
    
    return res;
}


int main()
{
    int t;
    cin>>t;
    
    vector<vector<int>> allLists(t);
    
    for(int i = 0; i < t; i++){
        // size of current list
        int n;
        cin>>n;
        
        for(int j = 0; j < n; j++){
            int x;
            cin>>x;
            allLists[i].push_back(x);
        }
        
    }
    
    
    vector <int> res;
    res = merge_K_sorted_lists(allLists);
    
    for(int i = 0; i < res.size(); i++){
        cout<<res[i]<<" ";
    }

    return 0;
}