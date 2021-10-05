// This is Correct Solution!!

// There's a problem with test case in case when a vertex has same wt path but from different vertice. 
// In some cases, if wtSoFar is equal, test case returns pathSoFar with larger size i.e more number of edges
//  & in some cases, pathSoFar with smaller size i.e lesser number of edges.

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
        string pathSoFar;
        int wtSoFar;
        
        Path(int v, string s, int w){
            curVertex = v;
            pathSoFar = s;
            wtSoFar = w;
        }
};


struct comparator {
    constexpr bool operator()(
        Path const& a,
        Path const& b)
    {
        // first compare wtSoFar. 
        // ASSUMPTION: In case of equality, print the path with more number of edges 
        return (a.wtSoFar > b.wtSoFar) || (a.wtSoFar == b.wtSoFar && a.pathSoFar.size() < b.pathSoFar.size());
    }
};

// JUST LIKE BFS EXCEPT IN PLACE OF QUEUE, USE PRIORITY_QUEUE
void dijkstraAlgo(vector<vector<Edge>>& graph, int* visited, int src)
{
    // make Path till src
    Path curPath(src, to_string(src), 0);
    
    priority_queue<Path, vector<Path>, comparator> q;
    q.push(curPath);
    
    while(!q.empty()){
        // 1. remove
        curPath = q.top();
        q.pop();
        
        // 2. mark *
        // if already visited => we had found a shorter path previously
        if(visited[curPath.curVertex] != 0){
            continue;
        }
        
        visited[curPath.curVertex] = 1;
        
        // 3. work
        cout<<curPath.curVertex<<" via "<<curPath.pathSoFar<<" @ "<<curPath.wtSoFar<<endl;
        
        // 4. add*
        for(Edge e : graph[curPath.curVertex]){
            if(visited[e.dst] == 0){
                Path temp(e.dst, curPath.pathSoFar + to_string(e.dst), curPath.wtSoFar + e.wt);
                q.push(temp);
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
    
    int visited[vertexCount] = {0};

    
    dijkstraAlgo(graph, visited, src);
    
    
    return 0;
}