/*###Begin banned keyword - each of the following line if appear in code will raise error. regex supported
define
include
using
###End banned keyword*/

#include <iostream>
using namespace std;

//###INSERT CODE HERE -
void QuickSort(int *arr, int l, int r,int fl){
    int pivot = arr[(l+r)/2];
    int i = l, j =r;
    if(fl==1){
        while(i<=j){
        while(arr[i]<pivot){
            i++;
        }
        while(arr[j]>pivot){
            j--;
        }
        if(i<=j){
            swap(arr[i],arr[j]);
            i++;j--;
        }
    }
    if(l<j) QuickSort(arr,l,j,1);
    if(r>i)QuickSort(arr,i,r,1);
    }
    else {
        while(i<=j){
        while(arr[i]>pivot){
            i++;
        }
        while(arr[j]<pivot){
            j--;
        }
        if(i<=j){
            swap(arr[i],arr[j]);
            i++;j--;
        }
    }
        if(l<j) QuickSort(arr,l,j,0);
        if(r>i)QuickSort(arr,i,r,0);
    }
    
}
int main(){
    int *a = NULL;
    int n;
    cin>>n;
    a = new int [n];
    for(int i = 0;i < n;i ++){
        cin>>a[i];
    }
    int *b = new int [n];
    int nb=0;
    int *c = new int [n];
    int nc = 0;
    for(int i =0;i < n;i++){
        if(a[i]%2==0){
            b[nb++] = a[i];
        }
        else {c[nc++]=a[i];}
    }
    QuickSort(b,0,nb-1,1);
    QuickSort(c,0,nc-1,0);
    nb = nc = 0;
    for(int i = 0;i < n;i ++){
        if(a[i]%2 == 0){
            a[i] = b[nb++];
        }
        else{
            a[i] = c[nc++];
        }
    }
    cout<<"Sorted Array: ";
    for(int i =0 ;i < n ;i ++){
        cout<<a[i]<<" ";
    }
    return 0;
}



