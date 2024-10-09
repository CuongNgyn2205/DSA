/*###Begin banned keyword - each of the following line if appear in code will raise error. regex supported
sort
stable_sort
partial_sort
partial_sort_copy
sort_heap
set
multiset
map
unordered_map
define
include
###End banned keyword*/

#include <iostream>
#include <vector>
using namespace std;

//###INSERT CODE HERE -
void inputArray(int*a , int n)
{
    for(int i = 0 ;i < n ;i ++)
    {
        cin>>a[i];
    }
}
void QuickSort(int *a, int l, int r)
{
    int i = l, j = r;
    int pivot = a[l + (r - l)/2];
    while(i<=j){
        while(a[i] < pivot){
            i ++;
        }
        while(a[j] > pivot){
            j --;
        }
        if(i<=j){
            swap(a[i],a[j]);
            i++;j--;
        }
        
    }
    if(l < j)
    {
        QuickSort(a,l,j);
    }
    if(r > i)
    {
        QuickSort(a,i,r);
    }
}
int MEX(int* a, int n){
    int mex = 0;
    for(int i = 0 ;i < n;i ++){
        if(a[i] == mex ){
            mex ++;
        }
    }
    return mex;
}
int main(){
    int n ; cin>>n;
    int *a = new int [n];
    inputArray(a,n);
    QuickSort(a,0,n-1);
    cout<<MEX(a,n)<<endl;
    delete[] a;
    return 0;
}