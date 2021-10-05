#include<iostream>
#include<string>
#include<stack>
#include<vector>
#include<utility>
using namespace std;

class Edge {
    public:
        int src, dst;

        // parameterized constructor
        Edge(int u, int v){
            src = u;
            dst = v;
        }
    
};


void topologicalSort(vector<vector<Edge>>& graph, bool* visited, stack<int>& st, int source)
{
    // mark it visited
    visited[source] = true;
    
    // visite it's "un-visited" neighbours
    for(Edge e : graph[source]){
        if(visited[e.dst] == false){
            topologicalSort(graph, visited, st, e.dst);
        }
    }
    
    // after exploring all the neighbours, add it to stack
    st.push(source);
}


int main()
{
    int vertexCount;
    cin>>vertexCount;
    
    int edgeCount;
    cin>>edgeCount;
    
    // graph is a 2d vector with #rows = vertexCount && each row contains a vector containing objects of Edge class.
    vector <vector<Edge>> graph(vertexCount);
    
    // for each edge
    for(int i = 0; i < edgeCount; i++){
        // take the source, destination of the edge
        int u, v;
        cin>>u>>v;
        
        // add the edge "u--v" inside the vector at the u-th index of graph
        graph[u].push_back(Edge(u, v));
        
    }
    
    
    bool visited[vertexCount] = {false};
    
    stack <int> st;
    
    // since graph can have multiple components
    for(int i = 0; i < vertexCount; i++){
        if(visited[i] == false){
            topologicalSort(graph, visited, st, i);
        }
    }
    
    // pop the content of stack one by one and print it to get the toplogicalSort
    while(!st.empty()){
        cout<<st.top()<<endl;
        st.pop();
    }
        
    
    return 0;
}