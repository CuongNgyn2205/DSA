#include<bits/stdc++.h>
using namespace std;
void inputArray(int *a, int n){
    a = new int [n];
    for(int i = 0 ; i < n ;i ++){
        cin>>a[i];
    }
}
void outputArray(int *a, int n){
    for(int i = 0 ; i < n ; i ++){
        cout<<a[i] << " ";
    }
}
void Merge(int *a, int l, int mid, int r){
    int *b = new int [mid];
    int *c = new int [(r-l)];
    int i = 0,j = 0;
    while(i<mid && j < (r-l)){
        
    }
}
void MergeSort(int *a,int l,int r){
    if(l>=r){
        return;
    }
    int mid = (l+r)/2;
    MergeSort(a,l,mid);MergeSort(a,mid+1,r);
    Merge(a,l,mid,r);
}
int main(){
    int *a, n;
    cin>>n;
    inputArray(a,n);
    MergeSort(a,0,n-1);
    outputArray(a,n);
    system("pause");
    return 0;
}