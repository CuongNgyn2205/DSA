/*###Begin banned keyword - each of the following line if appear in code will raise error. regex supported
define
include
###End banned keyword*/

#include <iostream>
using namespace std;


//###INSERT CODE HERE -
void Quick_Sort(int *a, int l, int r){
    int i = l, j = r;
    int mid = a[(l+r)/2];
    if(l>=r){
        return;
    }
    while(i<=j){
        while(a[i]<mid){
            i++;
        }
        while(a[j]>mid){
            j--;
        }
        if(i<=j){
            swap(a[i],a[j]);
            i++;j--;
        }
    }
    if(l<j){Quick_Sort(a,l,j);}
    if(r>i){Quick_Sort(a,i,r);}
}
int Binary_Search(int *a,int l, int r ,int key){
    while(l<=r){
        int mid = l + (r-l)/2;
        if(a[mid] == key){
            return 1;
        }
        else if(key > a[mid]){
            l = mid + 1;
        }
        else r = mid - 1;
    }
    return 0;
}
int main(){
    int n,k;
    cin>>n>>k;
    int *a = new int [n];
    for(int j = 0 ;j < n ;j ++){
        cin>>a[j];
    }
    Quick_Sort(a,0,n-1);
    int *b = new int[k];
    int nb = 0;
    int cnt =0 ;
    while(cnt<k){
        int temp;
        cin>>temp;
        b[nb++]=Binary_Search(a,0,n-1,temp);
        cnt++;
    }
    for(int i = 0 ;i < nb;i ++){
        if(b[i]==1){
            cout<<"YES"<<endl;
        }
        else cout<<"NO"<<endl;
    }
    return 0;
}