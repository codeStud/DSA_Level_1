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


class Path{
    public:
        int curVertex;
        int parentVertex;
        int edgeWt;
        
        Path(int v, int s, int w){
            curVertex = v;
            parentVertex = s;
            edgeWt = w;
        }
};


// we are doing operator overloading through this
bool operator < (const Path& p1, const Path& p2)
{
 
    // this will return true when second Path's weight
    // has lesser Value. Suppose we have p1.edgeWt = 5
    // and p2.edgeWt = 10 then the object which
    // have min val will be at the top(Min Heap)
    return p1.edgeWt > p2.edgeWt;
}


void primsAlgo(vector<vector<Edge>>& graph, bool* visited, int src)
{
    // for source vertex, parent = -1 and edgeWt = 0
    Path curPath(src, -1, 0);
    
    // We've done operator overloading of "<" which will return the element with the minimum val (Min Heap). 
    // So, NO NEED to write a comparable function separately or to declare pq as - priority_queue <Path, vector<Path>, comparable> pq;
    
    // Priority Queue of Pair class.
    priority_queue <Path> pq;
    pq.push(curPath);
    
    while(!pq.empty()){
        // remove
        curPath = pq.top();
        pq.pop();
        
        if(visited[curPath.curVertex] == true){
            continue;
        }
        
        visited[curPath.curVertex] = true;
        
        // print except for the source vertex
        if(curPath.parentVertex != -1){
            cout<<"["<<curPath.curVertex<<"-"<<curPath.parentVertex<<"@"<<curPath.edgeWt<<"]"<<endl;
        }
        
        // add neighbouring children
        for(Edge e : graph[curPath.curVertex]){
            if(visited[e.dst] == false){
                pq.push(Path(e.dst, curPath.curVertex, e.wt));
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
    
    int src;
    cin>>src;
    
    bool visited[vertexCount] = {false};
    
    primsAlgo(graph, visited, src);
    
    
    return 0;
}