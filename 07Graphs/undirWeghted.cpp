#include<iostream>
#include<vector>
#include<list>
using namespace std;
class Graph {
    int V;
    list<pair<int, int>>*l;
public:
    Graph(int V){
        this->V = V;
        l = new list<pair<int, int>>[V];
    }

    int addEdge(int u, int v, int wt, bool undir = true){
        l[u].push_back({v, wt});
        if(undir){
            l[v].push_back({u, wt});
        }
    }

    void printAdjList(){
        for(int u=0; u<V; u++){
          list<pair<int, int>> neighbors = l[u];
          cout<<u<<"->";
          for(auto v : neighbors){
            cout<<"("<<v.first<<", "<<v.second<<") ";
          }
          cout<<endl;

        }
    }

    bool undir
};
int main(){
    // Create a graph with 4 vertices and add weighted edges
    Graph graph(4);
    graph.addEdge(0, 1, 10);
    graph.addEdge(1, 2, 20);
    graph.addEdge(2, 3, 30);
    graph.addEdge(3, 0, 40);

    cout<<"Graph created successfully!"<<endl; 
    graph.printAdjList();

    return 0;
}