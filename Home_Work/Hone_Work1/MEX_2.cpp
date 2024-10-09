/*###Begin banned keyword - each of the following line if appear in code will raise error. regex supported
define
include
sort
stable_sort
partial_sort
partial_sort_copy
sort_heap
set
multiset
map
unordered_map
###End banned keyword*/

#include <iostream>
#include <vector>
using namespace std;


//###INSERT CODE HERE -
int binarySearch(vector<int> a,int key){
    int l = 0, r = a.size() - 1;
    while(l<=r){
        int mid = l + (r-l)/2;
        if(a[mid] > key){
            r = mid - 1;
        }
        else if(a[mid] < key){
            l = mid + 1;
        }
        else if( a[mid] == key){
            return 1;
        }
    }
    return key;
}
void MEX(vector<int> a,vector<int> &b){
    int mex = 0;
    for(int i =0 ;i < a.size();i  ++){
        int exist = binarySearch(b,mex);
        while(1){
            if(exist == 1){
                cout<<mex<<" ";
            }
            else if(exist == mex){
                mex++;
                break;
            }
        }
    }
}
void outputVec(vector<int> a){
    for(int i = 0;i < a.size() ;i ++){
        cout<<a[i]<<" ";
    }
}
int main(){
    vector<int> a;
    int n;cin>>n;
    for(int i = 0;i < n;i ++){
        int temp;
        cin>>temp;
        a.push_back(temp);
    }
    vector<int> b;
    MEX(a,b);
    outputVec(b);

    return 0;
}