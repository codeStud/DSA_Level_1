#include<iostream>
#include<string>
#include<stack>
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


void iterativeDFS(vector<vector<Edge>>& graph, bool* visited, int source)
{
    // make pair of vertex and path to it
    pair <int, string> curPair = make_pair(source, to_string(source));
    
    // push the curPair
    stack <pair<int, string>> st;
    st.push(curPair);
    
    while(!st.empty()){
        // 1. remove
        curPair = st.top();
        st.pop();
        
        // 2. mark *
        if(visited[curPair.first] == true){
            continue;
        }
        
        visited[curPair.first] = true;
        
        // 3. work
        cout<<curPair.first<<"@"<<curPair.second<<endl;
        
        // 4. Add neighbours
        for(Edge e : graph[curPair.first]){
            if(visited[e.dst] == false){
                st.push(make_pair(e.dst, curPair.second + to_string(e.dst)));
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
        
        graph[v].push_back(Edge(v, u, cost));
        
    }
    
    int source;
    cin>>source;
    
    bool visited[vertexCount] = {false};
    
    iterativeDFS(graph, visited, source);
        
    
    return 0;
}