#include<bits/stdc++.h>
using namespace std; 
void outputArray(int *a, int n){
    cout<<"Sorted Array: ";
    for(int i = 0 ;i < n ;i ++){
        cout<<a[i]<< " ";
    }
}   
void Quick_Sort(int *a, int l, int r,int &cnt){
    int mid = (l + r)/ 2;
    int pivot = a[mid];
    int i = l, j = r;
    if(l >= r){
        return;
    }
    while(i<=j){
        while(a[i] < pivot){
            i++;
        }
        while(a[j] > pivot){
            j--;
        }
        if(i <= j){
            swap(a[i],a[j]);
            i++;j--;
            cnt++;
        }
    }
    if(l < j){
        Quick_Sort(a,l,j,cnt);
    }
    if(r > i){
        Quick_Sort(a,i,r,cnt);
    }
}
int main(){
    int n;
    cin>>n; int *a = new int [n];
    for(int i =0 ; i < n ;i ++){
        cin>>a[i];
    }
    int l = 0, r = n - 1;
    int cnt = 0;
    Quick_Sort(a,l,r,cnt);
    outputArray(a,n);
    cout<<endl;
    cout<<"Number of times to swap 2 numbers: "<<cnt;
    return 0;
}