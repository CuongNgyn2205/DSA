#include<bits/stdc++.h>
using namespace std;
int Binary_Search(int *a, int n, int &mid_changed, int key){
    int l = 0, r = n - 1;
    while(l <= r){
        int mid = l + (r-l)/2;
        mid_changed++;
        if(a[mid] == key){
            return mid;
        }
        if(a[mid] < key){l = mid + 1;}
        else {r = mid - 1;}
    }
    return -1;
}
int main(){
    int *a = NULL;
    int n ; cin>>n;
    a = new int [n];
    for(int i = 0 ;i < n ;i ++){
        cin>>a[i];
    }
    int mid_changed = 0;
    int key; cin>>key;
    int result = Binary_Search(a,n,mid_changed,key);
    if(result != -1){
        cout<<result<<endl<<mid_changed;
    }
    else {
        cout<< -1<<endl;    
    }
    return 0;
}