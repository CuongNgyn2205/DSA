#include<bits/stdc++.h>
using namespace std;
void inputGraph(vector<vector<int>> &G, int v, int e)
{
    G.resize(v, vector<int>(v, 0));
    int x, y;
    for (int i = 0; i < e; i++)
    {
        cin >> x >> y;
        G[x][y] = G[y][x] = 1;
    }
}

int main()
{

    int v, e, n;
    cin >> v >> e >> n;
    vector<vector<int>> G;
    stack<int> path;
    inputGraph(G, v, e);

    return 0;
}
