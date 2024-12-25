/*###Begin banned keyword - each of the following line if appear in code will raise error. regex supported
define
include
using
###End banned keyword*/

#include<iostream>
using namespace std;

void inputGraph(bool*[], int);
void process(bool*[], int, int);



int main()
{
	int v, e, n; //v: số đỉnh, e: số cạnh, n: số thao tác
	cin >> v >> e >> n;

	bool **G; // ma trận toàn số 0, 1 nên kiểu bool hay int đều được


//###INSERT CODE HERE -
    G = new bool *[v];
    for(int i =0 ; i < v;i++){
        G[i] = new bool[v]{0};
    }
    int x,y;
    for(int i = 0;i < e;i++){
        cin>>x>>y;
        G[x-1][y-1] = 1;
    }
    int op,u,i;
    for(int k =0 ; k < n;k ++){
        cin>>op;
        if(op == 1){
            cin>>u>>i;
            if(G[u-1][i-1]){
                cout<<"TRUE"<<endl;
            }else{
                cout<<"FALSE"<<endl;
            }
        }
        else{
            cin>>u;
            int fl = 0;
            for(int j =0 ;j < v;j++){
                if(G[u-1][j]){
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
    return 0;
}