#include<bits/stdc++.h>
using namespace std;
class Graph{
    vector<string> names;
    vector<vector<int>> matrix;
    map<string,int> toindex;
    public:
    void inputGraph(int e){
        set<string> vertices;
        vector<pair<string,string>>edges;
        string x, y;
        for (int i = 0; i < e; i++) {
            cin >> x >> y;
            edges.push_back({x, y});
            vertices.insert(x);
            vertices.insert(y);
        }
        int n = vertices.size();
        names = vector<string>(n);
        matrix = vector<vector<int>>(n, vector<int>(n, 0));

        int index = 0;
        for (const auto& vertex : vertices) {
            names[index] = vertex;
            toindex[vertex] = index++;
        }
    }
    int degreeOfVertex(int index){
        int bac = 0;
        for(int i = 0 ;i < matrix.size();i ++){
            if(matrix[index][i] == 1 && i!= index){
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
    bool isCompleteGraph(int v){
        for(int i =0 ;i <matrix.size();i++){
            if(degreeOfVertex(i)!=v-1)
            return false;
        }
        return true;
    }
};
int main(){
    int e;
    Graph G;
    G.inputGraph(e);
    if(G.isCompleteGraph()){
        cout<<"TRUE\n";
    }
    else{
        cout<<"FALSE\n";
    }
    return 0;
}
