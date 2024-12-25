#include<bits/stdc++.h>
using namespace std;
class Graph{
    vector<string> names;
    vector<vector<int>> matrix;
    map<string,int> toindex;
public:
    void inputGraph(int v){
        matrix = vector<vector<int>>(v,vector<int>(v,0));
        names = vector<string>(v,"");
        string x,y;
        for(int i =0 ;i < v;i++){
            cin>>x;
            names[i] = x;
            toindex[x] = i;
        }
        for(int i =0 ;i < v;i ++ ){
            for(int j = 0;j < v;j ++){
                cin>>matrix[i][j];
            }
        }
    }
    void process(){

    }
};
int main(){
    int v,e;
    cin>>v>>e;
    
}