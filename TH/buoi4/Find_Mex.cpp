/*###Begin banned keyword - each of the following line if appear in code will raise error. regex supported
sort
stable_sort
partial_sort
partial_sort_copy
sort_heap
###End banned keyword*/

//###INSERT CODE HERE -
#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin>>n;
    int *a = new int[n];
    map <int,int> A;
    for(int i =0 ;i < n; i++){
        cin>>a[i];
        A[a[i]] = 1;
    }
    int x = 0;
    while (A.find(x) != A.end()) {
        x++;  
    }
    cout<<x;
    return 0;
}