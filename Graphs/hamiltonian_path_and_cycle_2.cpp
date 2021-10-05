#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class Edge{
    public:
    int src, dst, wt;
    
    Edge(int u, int v, int w)
    {
        src = u;
        dst = v;
        wt = w;
    }
};

vector<string> ans;

void print_hamiltonian(vector<vector<Edge>>& graph, vector<bool>& visited, int start, int u, string asf, int count, int v)
{
    if(count == v){
        string final = asf;
        
        int flag = 0;
        for(Edge e : graph[u]){
            if(e.dst == start){
                // cout<<"*"<<endl;
                final += "*";
                flag = 1;
            }
        }
        if(flag == 0){
            // cout<<"."<<endl;
            final += ".";
        }
        
        ans.push_back(final);
        
        return;
    }
    
    visited[u] = true;
    for(Edge e : graph[u]){
        if(visited[e.dst] == false){
            print_hamiltonian(graph, visited, start, e.dst, asf + to_string(e.dst), count+1, v);
        }
    }
    visited[u] = false;
}


int main()
{
    int v, e;
    cin>>v>>e;
    
    vector<vector<Edge>> graph(v);
    for(int i = 0; i < e; i++){
        int u, v, w;
        cin>>u>>v>>w;
        
        graph[u].push_back(Edge(u, v, w));
        graph[v].push_back(Edge(v, u, w));
    }
    
    int start;
    cin>>start;
    
    vector<bool> visited(e, false);
    print_hamiltonian(graph, visited, start, start, to_string(start), 1, v);
    
    sort(ans.begin(), ans.end());
    for(string s : ans){
        cout<<s<<endl;
    }
    
    return 0;
}