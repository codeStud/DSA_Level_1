#include<iostream>
#include<vector>
using namespace std;

class Edge{
    public:
        // no need of weight here
        int src, dst;
        
        Edge(int u, int v)
        {
            src = u;
            dst = v;
        }
};


void generateComponent(vector<vector<Edge>>& graph, vector<int>& curComp, bool* visited, int source)
{
    visited[source] = true;
    curComp.push_back(source);
    
    for(Edge e : graph[source]){
        if(visited[e.dst] ==  false){
            generateComponent(graph, curComp, visited, e.dst);
        }
    }
}


void perfectFriends(vector<vector<Edge>>& graph, int k)
{
    // vector to store the connected components, i.e friends in same club
    vector<vector<int>> comps;
    
    // visited array for 'n' friends
    bool visited[graph.size()] = {false};
    
    for(int i = 0; i < graph.size(); i++){
        if(visited[i] == false){
            vector<int> curComp;
            generateComponent(graph, curComp, visited, i);
            comps.push_back(curComp);
        }
    }
    
    int count = 0;
    
    // count of perfect friends = select all possible pair of component -> for each friend in the component, generate the combination and sum all the combinations
    for(int i = 0; i < comps.size(); i++){
        for(int j = i+1; j < comps.size(); j++){
            count += comps[i].size() * comps[j].size();
        }
    }
    
    cout<<count;
}


int main()
{
    int n, k;
    cin>>n>>k;
    
    // 2-D vector of n-rows with each index storing a vector of Edge
    vector<vector<Edge>> graph(n);
    
    // construct the graph with k-edges
    for(int i = 0 ; i< k; i++){
        int s1,s2;
        cin>>s1>>s2;
        
        // at s1 index, push s1--s2 edge
        graph[s1].push_back(Edge(s1, s2));
        
        // at s2 index, push s2--s1 edge
        graph[s2].push_back(Edge(s2, s1));
    }
    
    
    perfectFriends(graph, k);
    
    
    return 0;
}