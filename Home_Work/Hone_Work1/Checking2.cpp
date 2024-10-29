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
struct ID{
    string id;
    int n;
};
void init(ID &temp){
    temp.n = 1;
}
int find(vector<ID> a, ID temp){
    for(int i = 0;i < a.size() ; i ++){
        if(a[i].id == temp.id){
            return i;
        }
    }
    return -1;
}
int StrCmp(string a, string b){
    if(a.length() > b.length()){
        return 1;
    }
    else if( a.length() < b.length()){
        return -1;
    }
    else {
        return a.compare(b);
    }
}
void Merge(vector<ID> &a, int l, int m, int r){
    int n1 = m - l + 1;
    int n2 = r -m;
    vector<ID> lefsite(n1),rigsite(n2);
    for(int i = 0;i < n1;i ++){
        lefsite[i] = a[l + i];
    }
    for(int i = 0;i < n2; i++){
        rigsite[i] = a[m + i + 1];
    }
    int i = 0, j = 0, k = l;
    while(i < n1 && j < n2){
        if(lefsite[i].n > rigsite[j].n){
            a[k++] = lefsite[i++];
        }
        else if(lefsite[i].n == rigsite[j].n && StrCmp(lefsite[i].id,rigsite[j].id) < 0){
            a[k++] = lefsite[i++];
        }
        else {
            a[k++] = rigsite[j++];
        }
    }
    while(i < n1 ){
        a[k++] = lefsite[i++];
    }
    while(j < n2){
        a[k++] = rigsite[j++];
    }
}
void MergeSort(vector<ID> &a, int l, int r){
    if ( l < r){
        int mid = l + (r - l)/2;
        MergeSort(a,l,mid);
        MergeSort(a,mid+1,r);
        Merge(a,l,mid,r);
    }
}
void outputVec(vector<ID> a){
    for(int i = 0;i < a.size();i ++){
        cout<<a[i].id << " "<<a[i].n<<endl;
    }
}
int main(){
    vector<ID> a;
    int n; cin>>n;
    for(int i = 0;i < n;i ++){
        ID temp;
        cin>>temp.id;
        init(temp);
        int pos = find (a,temp);
        if(pos!=-1){
            a[pos].n++;
        }
        else {
            a.push_back(temp);
        }
        
    }
    MergeSort(a,0,a.size()-1);
    outputVec(a);
    return 0;
}