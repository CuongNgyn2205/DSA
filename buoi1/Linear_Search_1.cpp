/*###Begin banned keyword - each of the following line if appear in code will raise error. regex supported
define
include
###End banned keyword*/

#include <iostream>
using namespace std;
int main()
{
//###INSERT CODE HERE -
    int n; cin>>n;
    int *a = new int [n];
    for(int i = 0 ; i < n ;i ++){
        cin>>a[i];
    }
    int m; cin>>m;int x; 
    for(int i = 0 ;i < m ;i ++){
        cin>>x;
        int j;
        for( j = 0; j < n ; j++){
            if(a[j] == x){
                cout<<j;
                cout<<endl;
                break;
            }
        }
        if(j == n){
            cout<<-1;
            cout<<endl;
        }
    }
    return 0;
}
