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
}
void quick_Sort(vector<P> &list, int l, int r){
    int i = l, j = r;
    while(i<=j){
        P pivot = list[l + (r-l)/2];
        while((list[i].x < pivot.x) ||(list[i].x == pivot.x && list[i].y < pivot.y)){i++;}
        while((list[j].x > pivot.x) || (list[j].x == pivot.x && list[j].y > pivot.y)){j--;}
        if(i<=j){
            swap(list[i],list[j]);
            i++;
            j--;
        }
       
    }
    if(l < j){
        quick_Sort(list,l,j);
    }
    if(r > i){quick_Sort (list,i,r);}
}
int main(){
    vector<P> list;
    int n;cin>>n;
    inputVec(list,n);
    quick_Sort(list,0,n-1);
    outputVec(list);
    return 0;
}