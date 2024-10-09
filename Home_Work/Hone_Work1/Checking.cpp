/*###Begin banned keyword - each of the following line if appear in code will raise error. regex supported
sort
stable_sort
partial_sort
partial_sort_copy
sort_heap
set
map
multi_set
unordered_map
merge
define
include
###End banned keyword*/

#include <iostream>
#include <vector>
using namespace std;


//###INSERT CODE HERE -
int checking(vector<string> list){
    vector<string> uni;
    for(int i = 0;i < list.size(); i++){
        int fl = 0;
        for(int j = 0 ;j < uni.size(); j ++){
            if(list[i] == uni[j]){
                fl = 1;
                break;
            }
        }
        if(!fl){
            uni.push_back(list[i]);
        }
    }
    return uni.size();
}
int main(){
    vector<string> list;
    int n;
    cin>>n;
    for(int i = 0 ;i < n;i ++){
        string temp;
        cin>>temp;
        list.push_back(temp);
    }
    cout<<checking(list)<<endl;
    return 0;
}