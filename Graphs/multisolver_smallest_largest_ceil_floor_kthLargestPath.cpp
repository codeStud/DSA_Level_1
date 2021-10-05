#include<iostream>
#include<string>
#include<vector>
#include<climits>
#include<algorithm>
#include<utility>
#include<queue>
using namespace std;

// initialise global variables to store the final answers
int smallestPathWt = INT_MAX;
string smallestPath = "";

int largestPathWt = INT_MIN;
string largestPath = "";

int criteriaFloorWt = INT_MIN;
string criteriaFloorPath = "";

int criteriaCeilWt = INT_MAX;
string criteriaCeilPath = "";

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


// Structure of the operator overloading for comparison.
// Creates minHeap with "smallest-wt path" at the top. (Sort by second element of pair)
struct comparator {
    constexpr bool operator()(
        pair<string, int> const& a,
        pair<string, int> const& b)
        const noexcept
    {
        return a.second > b.second;
    }
};


void printAllPaths(int u, int v, vector<vector<Edge>>& graph, bool* visited, string curPath, int curPathWt, int criteria, int k, priority_queue<pair <string, int>, vector<pair <string, int>>, comparator>& pq)
{
    // print the ans when you reach dest
    if(u == v){
        // smallest path
        if(curPathWt < smallestPathWt){
            smallestPathWt = curPathWt;
            smallestPath = curPath;
        }
        
        // largest path
        if(curPathWt > largestPathWt){
            largestPathWt = curPathWt;
            largestPath = curPath;
        }
        
        // just larger path (smallest in larger values)
        if(curPathWt > criteria){
            if(curPathWt < criteriaCeilWt){
                criteriaCeilWt = curPathWt;
                criteriaCeilPath = curPath;
            }
        }
        
        // just smaller than criteria (largest in smaller values)
        if(curPathWt < criteria){
            if(curPathWt > criteriaFloorWt){
                criteriaFloorWt = curPathWt;
                criteriaFloorPath = curPath;
            }
        }
        
        // put first k paths directly in the minHeap
        if(pq.size() < k){
            pq.push(make_pair(curPath, curPathWt));
        }
        // else if the curPathWt is greater than the smallest wt in pq, pop the smallest element and push the curPath. This way pq will always have "k largest elements"
        else{
            if(curPathWt > pq.top().second){
                pq.pop();
                pq.push({curPath, curPathWt});
            }
        }
        
        return;
    }
    
    // mark the current node visited
    visited[u] = true;
    
    // visit all it's "unvisited" neighbouring nodes
    for(Edge edge : graph[u]){
        if(visited[edge.dst] == false){
            printAllPaths(edge.dst, v, graph, visited, 
            curPath + to_string(edge.dst), curPathWt + edge.wt, criteria, k, pq);
        }
    }
    
    // un-visit the current node after discovering all it's neighbours
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
    
    int srcVertex, dstVertex, criteria, k;
    cin>>srcVertex>>dstVertex>>criteria>>k;
    
    // declare a priority queue (Min Heap) of PAIR(string Path, int wt) of size k
    priority_queue <pair<string, int>, vector<pair <string, int>>, comparator> minHeap;
    
    // declare a visited array initialized with false
    bool visited[vertexCount] = {false};
    
    
    printAllPaths(srcVertex, dstVertex, graph, visited, to_string(srcVertex), 0, criteria, k, minHeap);
    
    
    cout<<"Smallest Path = "<<smallestPath<<"@"<<smallestPathWt<<endl;
    cout<<"Largest Path = "<<largestPath<<"@"<<largestPathWt<<endl;
    
    cout<<"Just Larger Path than "<<criteria<<" = "<<criteriaCeilPath<<"@"<<criteriaCeilWt<<endl;
    cout<<"Just Smaller Path than "<<criteria<<" = "<<criteriaFloorPath<<"@"<<criteriaFloorWt<<endl;
    
    // k-th largest element will be at the top of priority queue
    cout<<k<<"th largest path = "<<minHeap.top().first<<'@'<<minHeap.top().second<<endl;
    
    return 0;
}