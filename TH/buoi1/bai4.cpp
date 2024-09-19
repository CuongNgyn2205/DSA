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
    int *c = new int [n+m];
    int i = n, j = m, nc = 0;
    while(i<n && j<m){
        if(a[i]<b[j]){
            c[nc++] = a[i++];
        }
        else {
            c[nc++] =b[j++];
        }
    }
    while(i<n){
        c[nc++] = a[i++];
    }
    while(j<m){
        c[nc++]=b[j++];
    }
    for(int k = 0 ;k < nc ;k ++){
        cout<<c[k]<<" ";
    }
}
using namespace std;
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