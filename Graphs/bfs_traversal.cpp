#include<iostream>
#include<string>
#include<queue>
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


void bfs(vector<vector<Edge>>& graph, bool *visited, int src)
{
    // create a pair with current vertex and the path from src to current vertex
    pair <int, string> curPair;
    curPair = make_pair(src, to_string(src));
    
    queue <pair<int, string>> bfsQ;
    bfsQ.push(curPair);

    while(!bfsQ.empty()){
        // remove the front vertex
        curPair = bfsQ.front();
        bfsQ.pop();
        
        // if already visited, then continue
        if(visited[curPair.first] == true){
            continue;
        }
        
        // mark it visited
        visited[curPair.first] = true;
        
        // print
        cout<<curPair.first<<"@"<<curPair.second<<endl;
        
        // push the unvisited adjacent neighbours
        for(Edge e: graph[curPair.first]){
            if(visited[e.dst] == false){
                // before pushing, add the neighbour vertex in the path-so-far string
                bfsQ.push(make_pair(e.dst, curPair.second + to_string(e.dst)));
            }
            
        }
        
    }
    
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
    
    bool visited[vertexCount] = {false};
    bfs(graph, visited, srcVertex);
    
    return 0;
}