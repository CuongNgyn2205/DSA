/*###Begin banned keyword - each of the following line if appear in code will raise error. regex supported
define
include
using
###End banned keyword*/

#include <iostream>
#include <vector>
#include <map>
#include <string>
using namespace std;

//###INSERT CODE HERE -
class Graph{
    public:
    vector<vector<int>> G;
    map<int,string> k;
    map<string,int> a;
    void nhap(int v,int e){
        G.resize(v,vector<int>(v,0));
        string x,y;
    for(int i = 0;i < e;i++){
        cin>>x>>y;
        a[x] =i;
        k[i] = x;
    }
    for(int i = 0;i < e;i++){
        G[a[x]][a[y]] = 1;
    }
    }
    void myProcess(int n){
        int op;string u,i;
    for(int k =0 ; k < n;k ++){
        cin>>op;
        if(op == 1){
            cin>>u>>i;
            if(G[a[u]][a[i]]){
                cout<<"TRUE"<<endl;
            }else{
                cout<<"FALSE"<<endl;
            }
        }
        else{
            cin>>u;
            int fl = 0;
            for(int j =0 ;j < G.size();j++){
                if(G[a[u]][j] == 1){
                    cout<<k[j]<<" ";
                    fl = 1;
                }
            }
            cout<<endl;
            if(fl == 0){
                cout<<"NONE"<<endl;
            }

        }
    }
    }
};
int main()
{
    Graph G;
    int v, e, n; cin >> v >> e >> n;
    G.nhap(v, e);
    G.myProcess(n);
    return 0;
}

