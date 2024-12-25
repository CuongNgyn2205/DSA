/*###Begin banned keyword - each of the following line if appear in code will raise error. regex supported
sort
stable_sort
partial_sort
partial_sort_copy
sort_heap
map
set
###End banned keyword*/


#include<vector>
#include<iostream>
using namespace std;

int main()
{

//###INSERT CODE HERE -
    
    int n;cin>>n;
    
    int *b = new int[n];
    for(int i = 0; i<n ;i ++){
        cin>>b[i];
    }
    int maxval = 0;
    for(int i =0 ;i < n;i ++){
        if(maxval<b[i]){
            maxval = b[i];
        }
    }
    vector<int> a(maxval+1,0);
    for(int i= 0 ;i < n;i ++){
        if(b[i]<=maxval)
        a[b[i]] = 1;
    }
    for(int i =0 ;i <=maxval;i ++){
        if(a[i] == 0){
            cout<<i<<endl;
            return 0;
        }
    }
    cout<<maxval + 1<<endl;
    delete []b;
    return 0;

}



