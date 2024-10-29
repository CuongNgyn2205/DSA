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
void MEX(vector<int> a){
    vector<bool> b(a.size() + 1, false);
    
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
    MEX(a);

    return 0;
}