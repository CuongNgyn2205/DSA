#include<bits/stdc++.h>
using namespace std;
void inputArray(int *a, int n){
    for(int i = 0; i < n; i++){
        cin >>a[i];
    }
}
int binarySearch(int *a, int n, int x){
    int l = 0, r = n - 1, mid;
    while(l <= r){
        mid = l + (r - l) / 2;
        if(x < a[mid]){
            r = mid - 1;
        }
        else if ( x > a[mid]){
            l = mid + 1;
        }
        else 
            return mid;
    }
    return -1;
}
int main(){
    int n; cin >> n;
    int *a = new int[n];
    inputArray(a,n);
    int m; cin >> m;
    for(int i = 0; i < m ; i++){
        int x; cin >> x;
        cout << binarySearch(a,n,x)<<endl;
    }
    return 0;
}