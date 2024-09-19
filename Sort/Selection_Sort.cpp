#include<bits/stdc++.h>
using namespace std;
void inputArray(int *array, int n){
    for(int i = 0;i < n ;i ++){
        cin>>array[i];
    }
}
void outputArray(int *array, int n){
    for(int i = 0 ;i < n ;i ++){
        cout<<array[i] <<" ";
    }
}
void Selection_Sort(int *array, int n){
    for(int i = 0 ; i < n - 1; i ++){
        int min = i;
        for(int j = i + 1 ; j < n ; j++){
            if(array[min] > array[j]){
                min = j;
            }
        }
            swap(array[min],array[i]);
    }
}
int main(){
    int *array = NULL,n;
    cin>>n;
    array = new int [n];
    inputArray(array,n);
    Selection_Sort(array,n);
    outputArray(array,n);
    return 0;
}