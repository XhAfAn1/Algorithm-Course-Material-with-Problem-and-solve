#include <iostream>
#include <vector>
#include <list>
#include <stack>


using namespace std;

class Graph
{
private:
    int vertices;
    vector<list<int>> adjLists;

public:
    Graph(int v) : vertices(v)
    {
        adjLists.resize(v);
    }

    void addEdge(int src, int dest)
    {
        adjLists[src].push_back(dest);
        adjLists[dest].push_back(src);
    }

    vector<list<int>> getAdjList()
    {
        return adjLists;
    }

    void printGraph() const
    {
        for (int i = 0; i < vertices; i++)
        {
            cout << "Vertex " << i << ":";
            for (int neighbor : adjLists[i])
            {
                cout << " -> " << neighbor;
            }
            cout << endl;
        }
    }
};

void print_stack(stack<int> q)
{
    stack<int> temp = q;
    while (!temp.empty())
    {
        cout << temp.top() << " ";
        temp.pop();
    }
    cout << '\n';
}

void DFS(Graph G, int v, int s)
{
    stack<int> st;
    bool Vis[v];
    for (int i = 0; i < v; i++)
    {
        Vis[i] = false;
    }
    vector<list<int>> aL = G.getAdjList();
    Vis[s] = true;

    st.push(s);
    cout << endl
         << "The traversed Graph(DFS): ";
    while (!st.empty())
    {

        int curr = st.top();
        st.pop();

        cout << " " << curr;
        for (int ng : aL[curr])
        {

            if (!Vis[ng])
            {

                st.push(ng);
                Vis[ng] = true;

            }
        }
    }
}

int main()
{
    int vertices, edges, start;

    cout << "Enter the number of vertices: ";
    cin >> vertices;

    if (vertices <= 0)
    {
        cout << "Number of vertices must be positive!" << endl;
        return 1;
    }

    Graph graph(vertices);

    cout << "Enter the number of edges: ";
    cin >> edges;

    cout << "Enter the edges (format: source destination):" << endl;
    for (int i = 0; i < edges; i++)
    {
        int src, dest;
        cin >> src >> dest;

        if (src >= vertices || dest >= vertices || src < 0 || dest < 0)
        {
            cout << "Invalid edge! Please enter vertices between 0 and " << vertices - 1 << "." << endl;
            i--;
        }
        else
        {
            graph.addEdge(src, dest);
        }
    }

    graph.printGraph();

    cout << "Enter the start vertice: ";
    cin >> start;

    DFS(graph, vertices, start);

    return 0;
}
