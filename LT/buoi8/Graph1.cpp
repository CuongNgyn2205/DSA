/*###Begin banned keyword - each of the following line if appear in code will raise error. regex supported
define
include
using
###End banned keyword*/

#include<iostream>
#include<vector>
using namespace std;
void inputGraph(vector<vector<int>>&G, int v,int e){
    G.resize(v,vector<int>(v,0));
    int x,y;
    for(int i = 0;i < e;i++){
        cin>>x>>y;
        G[x-1][y-1] = 1;
    }
}

void process(vector<vector<int>>&G, int v,int n){
    int op,u,i;
    for(int k =0 ; k < n;k ++){
        cin>>op;
        if(op == 1){
            cin>>u>>i;
            if(G[u-1][i-1] || G[i-1][u-1] ){
                cout<<"TRUE"<<endl;
            }else{
                cout<<"FALSE"<<endl;
            }
        }
        else{
            cin>>u;
            int fl = 0;
            for(int j =0 ;j < v;j++){
                if(G[u-1][j]  || G[j][u-1]){
                    cout<<j+1<<" ";
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

int main()
{

	int v, e, n;
	cin >> v >> e >> n;
	vector<vector<int> > G;

	inputGraph(G,v,e);
    process(G,v,n);

	return 0;
}
