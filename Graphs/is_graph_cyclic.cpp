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


bool isCyclic(vector<vector<Edge>>& graph, bool* visited, int src)
{
    queue <int> q;
    q.push(src);
    
    while(!q.empty()){
        int curVertex = q.front();
        q.pop();
        
    // if the current vertex is already visited => it must have been the neighbour of 2 vertices => it was added twice in the queue => it has path from 2 vertice => Cycle
        if(visited[curVertex] == true){
            return true;
        }
        
        visited[curVertex] = true;
        
        // push all the "un-visited" neighbours of curVertex to the queue
        for(Edge e : graph[curVertex]){
            if(visited[e.dst] == false){
                q.push(e.dst);
            }
        }
    }
    
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
    
    bool visited[vertexCount] = {false};
    
    // Graph might be diconnected and can have multiple components. Any one of the component can have a cycle. So, loop through all the vertices
    for(int i = 0; i < vertexCount; i++){
        
        // if the vertex isn't already visited
        if(visited[i] == false){
            bool cycle = isCyclic(graph, visited, i);
            if(cycle){
                cout<<"true"<<endl;
                return 0;
            }
        }
        
    }
    
    cout<<"false"<<endl;
    
    return 0;
}