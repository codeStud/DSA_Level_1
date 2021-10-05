#include<iostream>
#include<string>
#include<vector>
#include<utility>
using namespace std;

class Edge {
    public:
        int src, dst, wt;
        
        // parameterized constructor
        Edge(int u, int v, int w){
            src = u;
            dst = v;
            wt = w;
        }
    
};


void printOutput(vector<vector<int>>& comps)
{
    cout<<'[';
    for(int i = 0; i < comps.size(); i++){
        cout<<'[';
        
        for(int j = 0; j < comps[i].size(); j++){
            cout<<comps[i][j];
            j < comps[i].size()-1 ? cout<<", " : cout<<"";
        }
        
        i < comps.size()-1 ? cout<<"], " : cout<<"]";
    }
    cout<<']';
}


void generateComponent(vector<vector<Edge>>& graph, vector<int>& curComp, bool* visited, int src)
{
    // mark the src visited
    visited[src] = true;
    // add it to curComp
    curComp.push_back(src);
    
    // visit each "un-visited" child of the source
    for(Edge edge : graph[src]){
        if(visited[edge.dst] == false){
            // generate component starting from edge.dst as the source
            generateComponent(graph, curComp, visited, edge.dst);
        }
    }
}


void getConnectedComponents(vector<vector<Edge>>& graph, int vertexCount)
{
    // create a vector of vectors to store each component
    vector <vector<int>> comps;
    
    // create a visited array 
    bool visited[vertexCount] = {false};
    
    // find components from each "Un-visited" vertex
    for(int i = 0; i < vertexCount; i++){
        if(visited[i] == false){
            // create a vector to store the component starting from the i-th vertex
            vector <int> curComp;
            
            // get the component starting from i-th vertex
            generateComponent(graph, curComp, visited, i);
            
            // add the curComp to comps
            comps.push_back(curComp);
        }
    }
    
    printOutput(comps);
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
    
    
    getConnectedComponents(graph, vertexCount);
    
    return 0;
}