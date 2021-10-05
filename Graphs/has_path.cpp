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


bool hasPath(int u, int v, vector<vector<Edge>>& graph, bool *visited)
{
    // base case
    if(u == v){
        return true;
    }
    
    // make current node as visited
    visited[u] = true;
    
    // graph[u] contains a vector of Edge objects with source vertex as 'u'
    // Thus, note how the below range based for-loop is working. graph[u] has vector<Edge> at it's index. 
    // The value inside the vector<Edge> is of "type Edge", thus (Edge edge : graph[u]). (Can also use auto in the for-loop)
    
    for(Edge edge : graph[u]){
        if(visited[edge.dst] != true){
           // find if there is a path from u--v from any of the neighbours of u
           bool neighbourHasPath = hasPath(edge.dst, v, graph, visited);
           if(neighbourHasPath){
               return true;
           }
        }
    }
    
    // you've asked all the neighbours of u and none has path to v => return false
    return false; 
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
    
    int srcVertex, dstVertex;
    cin>>srcVertex>>dstVertex;
    
    bool visited[vertexCount] = {false};
    if(hasPath(srcVertex, dstVertex, graph, visited)){
        cout<<"true";
    }
    else{
        cout<<"false";
    }
    
    return 0;
}