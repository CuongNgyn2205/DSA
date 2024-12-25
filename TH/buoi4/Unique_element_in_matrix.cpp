/*###Begin banned keyword - each of the following line if appear in code will raise error. regex supported
define
include
###End banned keyword*/


#include <iostream>
using namespace std;


//###INSERT CODE HERE -
void inputMatrix(int a[][50],int &n, int &m){
    cin>>n>>m;
    for(int i =0 ;i < n;i ++){
        for(int j = 0;j <m;j++){
            cin>>a[i][j];
        }
    }
}
void outputMatrix(int a[][50],int n,int m){
    for(int i = 0;i < n;i ++){
        for(int j =0 ;j <m ;j ++){
            cout<<a[i][j]<<" ";
        }
        cout<<endl;
    }
}
void uniqueElements(int a[][50],int n,int m){
    int max = a[0][0];
    for(int i =0 ;i < n; i ++)
    for(int j = 0;j < m;j ++){
        if(a[i][j]>max){
            max = a[i][j];
        }
    }
    int *unique = new int[max+1];
    for(int i = 0;i <= max;i++){
        unique[i] = 0;
    }
    for(int i = 0;i < n;i ++){
        for(int j = 0 ;j < m;j ++){
            int val = a[i][j];
            unique[val]++;
        }
    }
    int fl = 0;
    for(int i = 0 ;i <=max;i++){
        if(unique[i] == 1){
            fl = 1;
        }
    }
    if(fl == 0){
        cout<<"No unique element in the matrix\n";
    }
    else {
        cout<<"Unique elements in the matrix:\n";
    }
    for(int i = 0 ; i <= max ;i++){
        if(unique[i]==1)
        cout<<i<<" ";
    }
    cout<<endl;
}
int main()
{
    int m,n,a[50][50];
    inputMatrix(a,n,m);
    cout<<"Matrix:\n";
    outputMatrix(a,n,m);
    uniqueElements(a,n,m);
    return 0;
}



