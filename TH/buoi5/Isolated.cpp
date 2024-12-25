/*###Begin banned keyword - each of the following line if appear in code will raise error. regex supported
###End banned keyword*/
// ###INSERT CODE HERE -
#include <iostream>
#include <vector>
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
int Isolated(vector<vector<int>> &G, int v)
{
    int count = 0;
    for (int i = 0; i < v; i++)
    {
        int fl = 1;
        for (int j = 0; j < v; j++)
        {
            if (G[i][j] == 1)
            {
                fl = 0;
                break;
            }
        }
        if (fl)
        {
            count++;
        }
    }
    return count;
}
int main()
{
    int v, e;
    cin >> v >> e;
    vector<vector<int>> G;
    inputGraph(G, v, e);
    cout << Isolated(G, v);
    return 0;
}
