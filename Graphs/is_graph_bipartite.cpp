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


bool isGraphBipartite(vector<vector<Edge>>& graph, int* visited, int src)
{
    // create a pair of {current-vertex, level-of-current-vertex}
    pair <int, int> curPair;
    curPair = make_pair(src, 0);
    
    queue <pair<int, int>> bfsQ;
    bfsQ.push(curPair);
    
    while(!bfsQ.empty()){
        // remove
        curPair = bfsQ.front();
        bfsQ.pop();

        // if it is already present in the queue
        if(visited[curPair.first] != -1){
            // check if the previous level of this node is equal to the current level we are trying to enter
            if(visited[curPair.first] != curPair.second){
                // ODD CYCLE => Not bipartite
                return false;
            }    
        }
        else{
            // mark the current-vertex with it's "current-level"
            visited[curPair.first] = curPair.second;
        }
        
        // visit it's neighbouring vertices
        for(Edge e : graph[curPair.first]){
            // if not visited
            if(visited[e.dst] == -1){
                // make pair and push to queue
                // level of neighbouring node = level of current node + 1
                bfsQ.push(make_pair(e.dst, curPair.second + 1));
            }
        }
        
    }
    
    return true;
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
    
    
    
    // visited[] will store the level each-vertex is stored at. Univisited vertex => -1
    int visited[vertexCount];
    
    // int visited[vertexCount] = {-1}; ```````it works only with 0````````````
    for(int i = 0; i < vertexCount; i++){
        visited[i] = -1;
    }
    
    // Graph might be diconnected and can have multiple components. Any one of the component can have a cycle. So, loop through all the vertices
    for(int i = 0; i < vertexCount; i++){
        
        // if the vertex isn't already visited
        if(visited[i] == -1){
            
            bool bipartite = isGraphBipartite(graph, visited, i);
            if(bipartite == false){
                cout<<"false"<<endl;
                return 0;
            }
            
        }
        
    }
    
    cout<<"true"<<endl;
    
    return 0;
}