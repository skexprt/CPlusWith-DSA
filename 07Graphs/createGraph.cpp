#include<iostream>
#include<vector>
#include<queue>
#include<list>
using namespace std;

class Graph{
    int V; 
    list<int> * l;
public:
    Graph(int V){
        this->V = V;
        l = new list<int>[V];
    }

    int addEdge(int u, int v, bool undir = true){
        l[u].push_back(v);
        if(undir){
            l[v].push_back(u);
        }
    }

    void printAdjList(){
        for(int u=0; u<V; u++){
          list<int> neighbors = l[u];
          cout<<u<<"->";
          for(auto v : neighbors){
            cout<<v<<" ";
          }
          cout<<endl;

        }
    }

    void bfs(int V){
        queue<int> q;
        vector<bool> visited(V, false);
        q.push(0);
        visited[0] = true;

        while (!q.empty())
        {
            int current = q.front();  // Get the front element of the queue currently being processed   
            q.pop();
            cout << current << " ";

            for (auto neighbor : l[current])
            {
                if (!visited[neighbor])
                {
                    visited[neighbor] = true;
                    q.push(neighbor);
                }
            }
        }
    }

    void dfs(int u, vector<bool> visited){// O(V + E)
        cout<<u<<" ";
        visited[u] = true;

        list<int> neighbors = l[u];
        for(int v : neighbors){
            if(!visited[v]){
                dfs(v, visited);
            }
        }
    }


    bool pathHelper(int src, int dest, vector<bool> &visited){
        if(src == dest){
            return true;
        }

        visited[src] = true;
        list<int> neighbors = l[src];
        for(int v : neighbors){
            if(!visited[v]){
                bool found = pathHelper(v, dest, visited);
                if(found){
                    return true;
                }
            }
        }
        return false;
    }
    bool hasPath(int src, int dest){ // O(V + E)
        vector<bool> visited(V, false);
        return pathHelper(src, dest, visited);
    }

    bool bipartite(){ // O(V + E)
        queue<int> q;
        vector<bool> vis(V, false);
        vector<int> color(V, -1);

        q.push(0);
        color[0] = 0;

        while(q.size() >0 ){
            int curr = q.front();
            q.pop();
            list<int> neighbors = l[curr];

            for(int v : neighbors){
                if(!vis[v]){
                    vis[v] = true;
                    color[v] = !color[curr];
                    q.push(v);
                }else{
                    if(color[v] == color[curr]){
                        return false;
                    }
                }
            }
        }
        return true;
    }
};


int main()
{
    // Create a graph with 4 vertices and add edges
    // Graph graph(4);
    // graph.addEdge(0, 1);
    // graph.addEdge(1, 2);
    // graph.addEdge(2, 3);

    // cout<<"Graph created successfully!"<<endl;
    // graph.printAdjList();


    
    // Graph graph(7);
    // graph.addEdge(0, 1);
    // graph.addEdge(0, 2);
    // graph.addEdge(1, 3);
    // graph.addEdge(1, 4);
    // graph.addEdge(2, 5);
    // graph.addEdge(2, 6);

    // // cout<<"Graph created successfully!"<<endl;
    // // graph.dfs(0, vector<bool>(7, false));
    

    // cout<<"Graph created successfully!"<<endl;
    // graph.hasPath(0, 5)
    //     ? cout << "Path exists between 0 and 5" << endl
    //     : cout << "No path exists between 0 and 5" << endl; 

    Graph graph(4);
    graph.addEdge(0, 1);
    graph.addEdge(0, 2);
    graph.addEdge(1, 3);
    graph.addEdge(2, 3);
    cout<< "Ghraph is bipartite :"<< graph.bipartite()<<endl;
    return 0;
}