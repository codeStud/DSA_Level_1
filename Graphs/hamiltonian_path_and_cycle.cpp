#include<iostream>
#include<string>
#include<unordered_set>
#include<vector>
#include<utility>
using namespace std;

class Edge {
    public:
        int src, dst, wt;
        
        // default constructor
        Edge(){
            src = -1;
            dst = -1;
            wt = -1;
        }
        
        // parameterized constructor
        Edge(int u, int v, int w){
            src = u;
            dst = v;
            wt = w;
        }
    
};



void hamiltonian(vector<vector<Edge>>& graph, unordered_set<int>& visited, int originalSource, int src, string curPath)
{
    // when on last vertex, visited size will be graph.size() - 1 as you haven't
    // yet pushed the current src element into the visited
    if(visited.size() == graph.size() - 1){
        cout<<curPath;
        
        bool cycleEdge = false;
        
        // check all the edges from this last vertex (src) 
        // if last vertex has an edge to originalSource => hamiltonian cycle
        for(Edge e : graph[src]){
            if(e.dst == originalSource){
                cycleEdge = true;
                break;
            }
        }
        
        if(cycleEdge){
            cout<<"*"<<endl;
        }
        else{
            cout<<"."<<endl;
        }
        
        return;
    }
    
    visited.insert(src);
    
    // visite all the neighnours of current src
    for(auto e : graph[src]){
        // if neighbour isn't visited alredy, then only visit
        if(visited.find(e.dst) == visited.end()){
            hamiltonian(graph, visited, originalSource, e.dst, curPath + to_string(e.dst));
        }
    }
    
    // after exploring all the neighbours, remove the current src from visited
    visited.erase(src);
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
        // take the source, destination and cost of the edge
        int u, v, cost; 
        cin>>u>>v>>cost;
        
        // add the edge "u--v" inside the vector at the u-th index of graph
        graph[u].push_back(Edge(u, v, cost));
        
        // add the edge "v--u" inside the vector at the v-th index of the graph 
        // (Bcz UNDIRECTED Graph)
        graph[v].push_back(Edge(v, u, cost));
    }
    
    int srcVertex;
    cin>>srcVertex;
    
    unordered_set<int> visited;
    
    
    // pass empty visited set & currentPath = srcVertex
    hamiltonian(graph, visited, srcVertex, srcVertex, to_string(srcVertex));
    
    
    return 0;
}