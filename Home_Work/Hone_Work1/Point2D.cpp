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
struct P{
    int x,y;
};
void inputVec(vector<P> &list, int n){
    for(int i = 0;i <n ;i ++){
        P temp;
        cin>>temp.x>>temp.y;
        list.push_back(temp);
    }
}
void outputVec(vector<P> list){
    for(int i = 0 ;i < list.size();i++){
        cout<<list[i].x<<" "<<list[i].y<<endl;
    }
    vector<P>().swap(list);
}
void sele_s(vector<P> &list){
    for(int i = 0 ;i < list.size() - 1;i ++){
        int min = i;
        for(int j = i + 1 ; j< list.size(); j ++){
            if(list[min].x > list[i].x){
                min = j;
            }
            else if ((list[min].x == list[i].x) && (list[min].y > list[i].y)){
                min = j;
            }
        }
        swap(list[i],list[min]);
    }
}
int main(){
    vector<P> list;
    int n;cin>>n;
    inputVec(list,n);
    sele_s(list);
    outputVec(list);
    vector<P>().swap(list);
    return 0;
}