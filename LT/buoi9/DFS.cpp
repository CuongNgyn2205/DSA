#include<bits/stdc++.h>
using namespace std;
class Graph{
    vector<string> names;
    vector<vector<int>> matrix;
    map<string,int> toindex;
    public:
    void inputGraph(int v,int e){
        matrix = vector<vector<int>> (v,vector<int>(v,0));
        names = vector<string> (v,"");
        string x,y;
        for(int i = 0;i < v;i ++){
            cin>>x;
            names[i] = x;
            toindex[x] = i;
        }
        for(int i =0 ;i < e;i++){
            cin>>x>>y;
            int k = toindex[x];
            int z = toindex[y];
            matrix[k][z] = matrix[z][k] = 1;
        }
    }
    int degreeOfVertex(int index){
        int bac = 0;
        for(int i = 0 ;i < matrix.size();i ++){
            if(matrix[index][i] == 1){
                bac++;
            }
        }
        return bac;
    }
    void degreeOfVertices(){
        for(int i =0 ;i < matrix.size();i++){
            cout<<degreeOfVertex(i)<<" ";
        }
    }
    void DFS(string s, string g){
        stack<string> open;
        open.push(s);
        vector<bool> close(matrix.size(),false);
        bool found = false;
        map<string,string> parent;
        while(!open.empty()){
            string p = open.top();
            open.pop();
            if(p == g){
                found = true;
                break;
            }
            close[toindex[p]] = true;
            for(int i =0 ;i < matrix.size();i ++){
                if(matrix[toindex[p]][i] != 0 && close[i] == 0){
                    open.push(names[i]);
                    close[i] = true;
                    parent[names[i]] = p;
                }
            }

        }
        if(!found){
            cout<<"Unreachable";
        }
        else{
            string curr = g;
            vector<string> print;
            for(string i = g; i != s; i = parent[i]){
                print.push_back(i);
            }
            print.push_back(s);
            reverse(print.begin(),print.end());
            for(int i =0 ;i < print.size();i++){
                cout<<print[i]<<" ";
            }
        }
    }
    void process(int n){
        string x,y;
        cin>>x>>y;
        DFS(x,y);
    }
};
int main(){
    int v,e;
    cin>>v>>e;
    Graph G;
    G.inputGraph(v,e);
    G.degreeOfVertices();
    G.process(e);
    return 0;
}