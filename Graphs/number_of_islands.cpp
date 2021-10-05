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


void generateComponent(vector<vector<int>>& graph,int i, int j, vector<vector<bool>>& visited)
{
    // if "out-of graph" OR "already visited" OR water at current vertex => return
    if(i < 0 || j < 0 || i >= graph.size() || j >= graph[0].size() ||
    visited[i][j] == true || graph[i][j] == 1){
        
        return;
    }
    
    
    // mark the current vertex visited
    visited[i][j] = true;
    
    // visit each "un-visited" neighbours of current vertex (up-down-left-right)
    generateComponent(graph, i-1, j, visited);
    generateComponent(graph, i, j+1, visited);
    generateComponent(graph, i+1, j, visited);
    generateComponent(graph, i, j-1, visited);
}


int main()
{
    int n, m;
    cin>>n>>m;
    
    vector<vector<int>> graph(n, vector<int>(m));
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cin>>graph[i][j];
        }
    }
    
    vector <vector<bool>> visited(n, vector<bool>(m));
    int islandCount = 0;
    
    // each cell is treated as vertex of the graph
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            
            // if the current vertex is land (Not Water) && not visited
            if(graph[i][j] == 0 && visited[i][j] == false){
                generateComponent(graph, i, j, visited);
                islandCount++;
            }
            
        }
    }
    
    cout<<islandCount<<endl;
    
    return 0;
}