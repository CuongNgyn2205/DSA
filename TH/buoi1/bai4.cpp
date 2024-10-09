/*###Begin banned keyword - each of the following line if appear in code will raise error. regex supported
define
include
###End banned keyword*/

#include <iostream>


//###INSERT CODE HERE -
using namespace std;
void inputArray(int *a, int n){
    for(int i = 0; i < n; i ++){
        cin>>a[i];
    }
}
void Merge(int *a, int n, int *b, int m){
    int * c = new int [n + m];
    int i = 0 , j = 0;
    int nc = 0;
    while(i < n && j < m){
        if(a[i] < b[j]){
            c[nc++] = a[i++];
        }
        else {
            c[nc++] = b[j++];
        }
    }
    while(i < n){
        c[nc++] = a[i++];
    }
    while(j < m){
        c[nc++] = a[j++];
    }
    for(int i = 0 ;i < nc;i ++){
        cout<<c[i]<< " ";
    }
}
int main(){
    int t = 0;
    cin>>t;
    int cnt = 0;
    int *a,*b,n,m;
    while( cnt < t){
        cin>>n>>m;
        a = new int [n];
        b = new int [m];
        inputArray(a,n);inputArray(b,m);
        Merge(a,n,b,m);
        delete[] a;
        delete[] b;
        cnt++;
    }
}