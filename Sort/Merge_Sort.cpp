#include<bits/stdc++.h>
using namespace std;
void inputArray(int *a, int n){
    for(int i = 0 ; i < n ;i ++){
        cin>>a[i];
    }
}
void outputArray(int *a, int n){
    for(int i = 0 ; i < n ; i ++){
        cout<<a[i] << " ";
    }
}
void MergeSort(int *a, int n){
    int l,r;
}
int main(){
    int *a, n;
    cin>>n;
    inputArray(a,n);
    MergeSort(a,n);
    outputArray(a,n);
    system("pause");
    return 0;
}