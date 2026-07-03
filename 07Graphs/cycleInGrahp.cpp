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

   
    bool undircycInGraph(int u, vector<bool> &visited, int parent){
        visited[u] = true;

        for(auto v : l[u]){
            if(!visited[v]){
                if(undircycInGraph(v, visited, u)){
                    return true;
                }
            }
            else if(v != parent){
                return true;
            }
        }
        return false;
    }

    bool isCycleInGraph(){
        vector<bool> visited(V, false);
        return undircycInGraph(0, visited, -1);
    }
};

int main(){
    Graph g(5);
    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(0, 3);
    g.addEdge(1, 2);
    g.addEdge(3, 4);

    cout<<"Is there a cycle in the graph? "<<g.isCycleInGraph()<<endl;

    return 0;
    
}