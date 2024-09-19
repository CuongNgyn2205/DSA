#include<bits/stdc++.h>
using namespace std;
void inputArray(int *a, int n){
    for(int i = 0 ; i< n ;i ++){
        cin>>a[i];
    }
}

void outputArray(int *a, int n){
    for(int i  =0 ; i < n ;i ++){
        cout<<a[i]<<" ";
    }
}
void Insertion_Sort(int *a, int n){
    for(int i = 1 ;i < n ;i ++){
        int key = a[i];
        int j = i - 1;
        for(j; j >= 0 && a[j] > key; j --){
            a[j+1] = a[j];
            outputArray(a,n); cout<<endl;
        }
        a[j+1] = key;
        outputArray(a,n);cout<<endl;
    }
}
int main(){
    int n; cin>>n;
    int *a = new int [n];
    inputArray(a,n);
    Insertion_Sort(a,n);
    return 0;
}