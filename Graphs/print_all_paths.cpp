#include<iostream>
#include<string>
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


void printAllPaths(int u, int v, vector<vector<Edge>>& graph, bool* visited, string ans)
{
    // print the ans when you reach dest
    if(u == v){
        cout<<ans<<endl;
        return;
    }
    
    // mark the current node visited
    visited[u] = true;
    
    // visit all it's "unvisited" neighbouring nodes
    for(Edge edge : graph[u]){
        if(visited[edge.dst] == false){
            // since, we need to see all the neighbours, don't return immediately when you find a path (see hasPath code)
            printAllPaths(edge.dst, v, graph, visited, ans + to_string(edge.dst));
        }
    }
    
    // un-visit the current node after discovering all it's neighbours so that it can become part of another path
    visited[u] = false;
}


int main()
{
    int vertexCount;
    cin>>vertexCount;
    
    int edgeCount;
    cin>>edgeCount;
    
    // graph is a 2d vector with #rows = vertexCount && each row containsa vector storing objects of Edge class.
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
    
    
    int srcVertex, dstVertex;
    cin>>srcVertex>>dstVertex;
    
    bool visited[vertexCount] = {false};
    
    // pass a string to store the ans, initialised with srcVertex
    printAllPaths(srcVertex, dstVertex, graph, visited, to_string(srcVertex));
    
    return 0;
}