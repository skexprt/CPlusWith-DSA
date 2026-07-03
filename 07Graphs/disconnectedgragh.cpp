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

    void dfsHelper(int u, vector<bool> &visited){// O(V + E)
        cout<<u<<" ";
        visited[u] = true;

        list<int> neighbors = l[u];
        for(int v : neighbors){
            if(!visited[v]){
                dfs(v, visited);
            }
        }
    }

    void dfs(){
        vector<bool> vis{V , false};

        for(int i=0; i<V; i++){
            if(!vis[i]){
                dfsHelper(i, vis);

                cout<<endl;
            }
        }
        cout<<endl;
    }
   
};

int main(){
    Graph g(7);
    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(1, 3);
    g.addEdge(4, 5);
    g.addEdge(5, 6);

    g.printAdjList();
    
}