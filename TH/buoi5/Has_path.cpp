#include<bits/stdc++.h>
using namespace std;
bool BFS(int start, int target, vector<bool> &visited, vector<vector<int>> &adj)
{
    queue<int> q;
    q.push(start);
    visited[start] = true;

    while (!q.empty())
    {
        int u = q.front();
        q.pop();
        if (u == target) 
            return true;

        for (int neighbor : adj[u])
        {
            if (!visited[neighbor])
            {
                visited[neighbor] = true;
                q.push(neighbor);
            }
        }
    }

    return false; 
}
int main(){
    int n,m;
    cin>>n>>m;
    vector<vector<int>> adj(n);
    vector<bool> visited(n, false);
    for(int i = 0;i < m;i ++){
        int u,v;
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
        if (BFS(u, v, visited, adj))
    {
        cout<<"CO\n";
    }
    else
    {
        cout<<"KHONG\n";
    }
    }
    return 0;
    
}