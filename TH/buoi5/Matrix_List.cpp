#include<bits/stdc++.h>
using namespace std;
struct Node{
    int vertex;
    Node* next;
};
struct Graph{
    int numVertices;
    Node** lists;
};
Node* GetNode(int x){
    Node* temp = new Node;
    temp->vertex = x;
    temp->next = NULL;
    return temp;
}
void CreateGraph(Graph &G,vector<vector<int>> V,int v){
    G.numVertices = v;
    G.lists = new Node*[v+1];
    for(int i = 1 ;i <= v;i ++){
        G.lists[i] = nullptr;
    }
    for(int i = 1 ;i <= v;i++){
        Node* last = NULL;
        for(int j = 1;j <= v;j++){
            if(V[i][j] == 1){
                Node* p = GetNode(j);
                if(G.lists[i] == NULL){
                    G.lists[i] = p;
                }
                else{
                    last->next = p;
                }
                last = p;
            }
        }
    }
}
void inputMatrix(vector<vector<int>> &V,int v){
    V.resize(v+1,vector<int>(v+1));
    for(int i = 1 ;i <= v;i++){
        for(int j = 1 ;j <= v;j++){
            cin>>V[i][j];
        }
    }
}
void Print(Graph G){
    for(int i = 1;i <= G.numVertices;i++){
        if(G.lists[i]==nullptr)continue;
        cout<<i <<"->";
        Node* p = G.lists[i];
        while(p){
            cout<<p->vertex<<" ";
            p = p->next;
        }
        cout<<endl;
    }
}
int main(){
    int v;
    cin>>v;
    vector<vector<int>> V;
    inputMatrix(V,v);
    Graph G;
    CreateGraph(G,V,v);
    Print(G);
    system("pause");
}