#include <bits/stdc++.h>
using namespace std;
class Graph
{
    vector<string> names;
    vector<vector<int>> matrix;
    map<string, int> toindex;
    int nOfVertices;

public:
    void inputGraph(int v)
    {
        nOfVertices = v;
        matrix = vector<vector<int>>(v, vector<int>(v, 0));
        names = vector<string>(v, "");
        string x, y;
        for (int i = 0; i < nOfVertices; i++)
        {
            cin >> x;
            names[i] = x;
            toindex[x] = i;
        }
        for (int i = 0; i < nOfVertices; i++)
        {
            for (int j = 0; j < nOfVertices; j++)
            {
                cin >> matrix[i][j];
            }
        }
    }
    void BFS(int s, int u){
        queue<int> open;
        open.push(s);
        vector<bool> close(nOfVertices, false);
        bool found = false;
        map<int, int> parent;
        int sum = 0;
        int went = 0;
        close[s] = true;
        while (!open.empty())
        {
            int p = open.front();
            open.pop();
            went++;
            if (p == u)
            {
                found = true;
                break;
            }
            for (int i = 0; i < nOfVertices; i++)
            {
                if (matrix[p][i] > 0 && !close[i])
                {
                    open.push(i);
                    parent[i] = p;
                    close[i] = true;
                }
            }
        }
        if (!found)
        {
            cout << "-unreachable-" << endl<< went << " " << 0 << endl;
        }
        else
        {
            vector<int> path;
            int curr = u;
            while (curr != s)
            {
                sum += matrix[parent[curr]][curr];
                path.push_back(curr);
                curr = parent[curr];
            }
            path.push_back(s);
            for (int i = path.size() - 1; i >= 0; i--)
            {
                cout << names[path[i]] << " ";
            }
            cout << endl<< went << " " << sum << endl;
    
        }
    }
    void process(int n)
    {
        string x, y;
        while (cin >> x >> y)
        {
            if (toindex.find(x) == toindex.end() || toindex.find(y) == toindex.end())
            {
                return;
            }
            BFS(toindex[x], toindex[y]);
        }
    }
};
int main()
{
    int v, e;
    cin >> v >> e;
    Graph G;
    G.inputGraph(v);
    return 0;
}