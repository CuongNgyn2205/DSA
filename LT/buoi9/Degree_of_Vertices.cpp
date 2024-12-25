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
};
int main(){
    int v,e;
    cin>>v>>e;
    Graph G;
    G.inputGraph(v,e);
    G.degreeOfVertices();
    return 0;
}