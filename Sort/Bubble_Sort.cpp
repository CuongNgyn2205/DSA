#include<bits/stdc++.h>
using namespace std;
void BBSort(int *a ,int n){
    for(int i = 0;i < n - 1; i ++){
        for(int j = 0 ;j < n - 1 ;j ++){
            if(a[j] > a[j + 1]){
                swap(a[j],a[j + 1]);
                for(int k = 0 ;k < n; k ++){
                    cout<<a[k]<<" ";
                }
                cout<<endl;
            }
        }
    }
}
int main(){
    int n; cin>>n;
    int *a = new int[n];
    for(int i= 0; i <n ;i ++){
        cin>>a[i];
    }
    BBSort(a,n);
    return 0;
}