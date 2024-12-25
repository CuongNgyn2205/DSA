#include <bits/stdc++.h>
using namespace std;
class compare
{
public:
    bool operator()(pair<int, int> a, pair<int, int> b)
    {
        if (a.first > b.first)
            return true;
        if (a.first == b.first && a.second < b.second)
            return true;
        return false;
    }
};
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
        for (int i = 0; i < v; i++)
        {
            cin >> x;
            names[i] = x;
            toindex[x] = i;
        }
        for (int i = 0; i < v; i++)
        {
            for(int j =0 ;j < v;j ++){
                cin>>matrix[i][j];
            }
        }
    }
    void process(int n)
    {   
        string x, y;
        for(int i =0 ;i < n;i ++){
            cin >> x >> y;
            Dijsktra(toindex[x],toindex[y]);
        }
        
    }
    void Dijsktra(int start, int target){
        priority_queue<pair<int, int>, vector<pair<int, int>>, compare> open;
        vector<bool> close(nOfVertices, false);
        map<int,int> parent;
        vector<int> d(nOfVertices,INT_MAX);
        open.push({0,start});
        d[start] = 0;
        bool found = false;
        while(!open.empty()){
            int p = open.top().second;
            open.pop();
            
            if(close[p] == 1){continue;}
            close[p] = true;
            if(p == target){
                found = true;
                break;
            }
            for(int q = nOfVertices - 1; q >= 0;q--){
                if(matrix[p][q] > 0 && !close[q]){
                    int d_new = d[p] + matrix[p][q];
                    if(d_new<d[q]){
                        d[q] = d_new;
                        open.push({d[q], q});
                        parent[q] =p;
                    }
                }
            }
        }
        if(!found){
            int visited = count(close.begin(), close.end(), true);
            cout<<"-unreachable-\n";
            cout << visited << " 0" << endl;
            return;
        }
        else{
            vector<int> path;
            int curr = target;
            while(curr != start){
                path.push_back(curr);
                curr = parent[curr];
            }
            path.push_back(start);
            for (int i = path.size() - 1; i >= 0; i--)
            {
                cout << names[path[i]] << " ";
            }
            cout << endl;
            int visited = count(close.begin(), close.end(), true);
            cout << visited << " " << d[target] << endl;
        
        }
    }
};
int main()
{
    Graph G;
    int v, n;
    cin >> v >> n;
    G.inputGraph(v);
    G.process(n);
    return 0;
}