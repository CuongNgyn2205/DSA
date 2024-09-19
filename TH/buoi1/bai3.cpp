#include<bits/stdc++.h>
using namespace std;
void Merge(int *a,int na, int *b, int nb){
    int *c = new int [na+nb];
    int i = 0, j = 0,nc = 0;
    while( i< na && j<nb){
        if(a[i]<b[j]){
            c[nc++] = a[i++];
        }
        else{
            c[nc++] = b[j++];
        }
    }
    while(i<na){
        c[nc++]=a[i++];
    }
    while(j<nb){
        c[nc++]=b[j++];
    }

    for(int k = 0;k < nc; k ++){
        cout<<c[k]<<" ";
    }
}
int main(){
    int na,nb;
    cin>>na;
    int *a = new int [na];
    int *b = new int [nb];
    for(int i = 0;i < na ;i ++){
        cin>>a[i];
    }
    cin>>nb;
    for(int i = 0;i <nb;i++){
        cin>>b[i];
    }
    cout<<endl;
    Merge(a,na,b,nb);
    return 0;
}