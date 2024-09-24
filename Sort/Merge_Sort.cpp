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
void Merge(int *b, int *c , int *a){
    int leftsize = (sizeof(a)/sizeof(a[0])/2);
    int rightsize = (sizeof(a)/sizeof(a[0])) - leftsize;
    int i = 0, l = 0, r = 0;
    while(l < leftsize && r < rightsize){
        if(b[l]<c[r]){
            a[i++] = b[l++];
        }
        else {
            a[i++] = c[r++];
        }
    }
    while(l<leftsize){a[i++] = b[l++];}
    while(r<rightsize){a[i++] = c[r++];}
}
void MergeSort(int *a,int n){
    int length = sizeof(a)/sizeof(a[0]);
    if(length <= 1){
        return;
    }
    int mid = length/2;
    int *b = new int [mid];
    int *c = new int [length - mid];
    int i = 0, j = 0;
    for(i;i<length;i++){
        if(i < mid){
            b[i] = a[i];
        }
        else {
            c[j] = a[i];
            j++;
        }
    }
    Merge(b,c,a);
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