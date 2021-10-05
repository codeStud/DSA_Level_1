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


int infectionSpread(vector<vector<Edge>>& graph, int* visited, int src, int t)
{
    // keep count of infected person
    int count = 0;
    
    // {personNo, timeOfInfection}
    pair <int, int> curPair;
    // src person, affected at time 1
    curPair = make_pair(src, 1);

    queue <pair<int, int>> bfsQ;
    bfsQ.push(curPair);
    
    while(!bfsQ.empty()){
        // remove
        curPair = bfsQ.front();
        bfsQ.pop();
        
        // if already infected => continue
        if(visited[curPair.first] > 0){
            continue;
        }
        
        // check if it is infected within given time 't'
        if(curPair.second > t){
            break;
        }
        
        // mark it infected
        visited[curPair.first] = curPair.second;
        
        // increase count of infected persons
        count += 1;
        
        // go to it's "un-infected" neighbours
        for(Edge e : graph[curPair.first]){
            if(visited[e.dst] == 0){
                // push it to bfsQ with infection at time t+1
                bfsQ.push(make_pair(e.dst, curPair.second + 1));
            }
        }
    }
    
    return count;
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
    
    int srcPerson, t;
    cin>>srcPerson>>t;
    
    // visited[] will store the level each-vertex is stored at. Univisited vertex => 0
    int visited[vertexCount] = {0};

    
    // It's a question of BFS
    cout<<infectionSpread(graph, visited, srcPerson, t);
    
    
    
    return 0;
}