#include<bits/stdc++.h>
using namespace std;
void inputVector(vector<int> &list,int &n){
    list.push_back(n);
}
void delete_object(vector<int>&list){
    int max = list[0];
    for(int i =0 ; i < list.back(); i ++){
        if(max < list[i]){
            max = list [i];
        }
    }
    for(int i = 0 ;i < list.back(); i ++){
        if(max == list[i]){
            list.erase(list.begin() + i);
        }
    }
}
void outputVector(vector<int> list){
    for(int i = 0 ;i < list.back(); i ++){
        cout<<list[i]<<endl;
    }
    cout<<endl;
}
void QuickSort(vector<int> &list, int l, int r){
    l = 0; r = list.back() - 1;
    int i = l, j = r;
    while(i<=j){
        int pivot = list[(l+r)/2];
        while(list[i]>pivot){
            i++;
        }
        while(list[j]<pivot){
            j--;
        }
        swap(list[i],list[j]);
    }
    if(l < j){
        QuickSort(list,l,j);
    }
    if(r > i){
        QuickSort(list,i,r);
    }
}
int main(){
    vector<int> list;
    while(1){
        int n;cin>>n;
        // else if( n == -1){
        //     delete_object(list);
        // }
        if(n != -1 || n != -2){
            inputVector(list,n);
        }
        else if(n == -2){
            QuickSort(list,0,list.back()-1);
            outputVector(list);
            break;
        }
    }
    
}