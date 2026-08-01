#include <iostream>
#include <vector>
#include <queue>
#include <list>
using namespace std;

class Graph
{
    int V;
    list<int> *l;
    bool isUndir;

public:
    Graph(int V, bool isUndir = true)
    {
        this->V = V;
        l = new list<int>[V];
        this->isUndir = isUndir;
    }

    int addEdge(int u, int v)
    {
        l[u].push_back(v);
        if (isUndir)
        {
            l[v].push_back(u);
        }
    }

    void printAdjList()
    {
        for (int u = 0; u < V; u++)
        {
            list<int> neighbors = l[u];
            cout << u << "->";
            for (auto v : neighbors)
            {
                cout << v << " ";
            }
            cout << endl;
        }
    }

    bool undircycInGraph(int u, vector<bool> &visited, int parent)
    {
        visited[u] = true;

        for (auto v : l[u])
        {
            if (!visited[v])
            {
                if (undircycInGraph(v, visited, u))
                {
                    return true;
                }
            }
            else if (v != parent)
            {
                return true;
            }
        }
        return false;
    }

    bool isCycleInGraph()
    {
        vector<bool> visited(V, false);
        return undircycInGraph(0, visited, -1);
    }

    bool dirCycleHelper(int src, vector<bool> &vis, vector<bool> &recPath)
    {
        vis[src] = true;
        recPath[src] = true;

        list<int> neighbors = l[src];

        for (int v : neighbors)
        {
            if (!vis[v])
            {
                if (dirCycleHelper(v, vis, recPath))
                {
                    return true;
                }
            }
            else if (recPath[v])
            {
                return true;
            }
        }

        recPath[src] = false;
        return false;
    }
    bool isCycleDir()
    {
        vector<bool> vis(V, false);
        vector<bool> recPath(V, false);

        for (int i = 0; i < V; i++)
        {
            if (!vis[i])
            {
                if (dirCycleHelper(i, vis, recPath))
                {
                    return true;
                }
            }
        }

        return false;
    }
};

int main()
{
    // Directed Graph
    Graph g(4, false);
    g.addEdge(1, 0);
    g.addEdge(0, 2);
    g.addEdge(2, 3);
    g.addEdge(3, 0);

    cout << g.isCycleDir() << endl;

    return 0;
}