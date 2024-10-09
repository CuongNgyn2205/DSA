/*###Begin banned keyword - each of the following line if appear in code will raise error. regex supported
sort
stable_sort
partial_sort
partial_sort_copy
sort_heap
###End banned keyword*/

//###INSERT CODE HERE -
#include<iostream>
#include<vector>
using namespace std;
struct P{
    int x,y;
};
void inputVec(vector<P> &list, int n){
    for(int i =0 ; i< n;i ++){
        P temp;
        cin>>temp.x>>temp.y;
        list.push_back(temp);
    }
    cout<<endl;
}
void outputVec(vector<P> list){
    for(int i =0 ;i < list.size();i ++){
        cout<<list[i].x << " "<<list[i].y<<endl;
    }
    vector<P>().swap(list);
}
<<<<<<< HEAD
void Merge(vector<P> &list,int l, int mid, int r){
    int n1 = mid - l + 1;
    int n2 = r - mid;
    vector<P> lefsi(n1);
    vector<P> risi(n2);
    for(int i = 0;i < n1; i ++){
        lefsi[i] = list[l + i];
    }
    for(int i = 0; i < n2; i ++){
        risi[i]= list[i+mid+1];
    }
    int i = 0, j = 0;
    while(i < n1 && j < n2){
        if(lefsi[i].x < risi[j].x || (lefsi[i].x == risi[j].x && lefsi[i].y >= risi[j].y)) {
            list[l++] = lefsi[i++];
        } else {
            list[l++] = risi[j++];
        }
    }
    while(i < n1){
        list[l++] = lefsi[i++];
    }
    while(j < n2){
        list[l++] = risi[j++];
    }

}
void MergeSort(vector<P> &list, int l, int r){
    if(l<r){
        int mid = l + (r - l )/2;
        MergeSort(list,l,mid);
        MergeSort(list,mid+1,r);
        Merge(list,l,mid,r);
    }
=======
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
>>>>>>> origin
}
int main(){
    vector<P> list;
    int n; cin>>n;
    inputVec(list,n);
<<<<<<< HEAD
    MergeSort(list,0,list.size()-1);
    outputVec(list);
    return 0;   
=======
    sele_s(list);
    outputVec(list);
    vector<P>().swap(list);
    return 0;
>>>>>>> origin
}