#include<bits/stdc++.h>
using namespace std;
struct Node{
    int val;
    Node* next;
};
struct List{
    Node* Head,Tail;
};
void inputStack(stack<int> &list,int n){
    int temp;
    for(int i =0 ;i < n ;i++){
        cin>>temp;
        list.push(temp);
    }
}
void solution(stack<int> &list, int m){
    if(list.empty()){
        return;
    }
    else if(list.)
}
int main(){
    stack<int> list;
    int n,m;
    cin>>n>>m;
    inputStack(list,n);
    for(int i = 0;i < m ;i ++){
        int temp;
        cin>>temp;
        solution(list,temp);
    }

}