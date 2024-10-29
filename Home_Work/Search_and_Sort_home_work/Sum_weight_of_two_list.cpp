

#include <iostream>
#include <vector>
using namespace std;


void QS(int*a,int l , int r){
    int i = l, j = r;
    int mid = (l + r)/2;
    while(i <= j){
        while(a[i] < a[mid]){
            i++;
        }
        while(a[j] > a[mid]){
            j--;
        }
        if(i<=j){
            swap(a[i],a[j]);
            i++;j--;
        }
    }
    if(l < j){
        QS(a,l,j);
    }
    if(i < r){
        QS(a,i,r);
    }
}
int isFullystored(int*a,int n)
{
    return ((a[n-1] - a[0]) + (a[n-2] - a[1]));

}
int main(){
    int T;cin>>T;
    int cnt = 0;
    while(cnt<T){
        int n ;cin>>n;
        int* a = new int [n];
        for(int i =0 ;i < n; i ++){
            cin>>a[i]; 
        }
        QS(a,0,n-1);
        cout<<isFullystored(a,n);
        delete[] a;
        cnt++;
    }
    return 0;
}