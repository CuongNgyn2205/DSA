#include<bits/stdc++.h>
using namespace std;
struct Node {
    int data;
    Node *next;
};
struct List {
    Node *head;
    Node *tail;
};
struct Hashtable {
    int n;
    int m;
    float LOAD;
    List *pl;
};
int Hashfunc(int x, int m){
    return x % m;
}
void addTail(List &L,int x){
    Node *p = new Node;
    p->data = x;
    p->next = NULL;
    if(L.head == NULL){
        L.head = p;
        L.tail = p;
    }
    else {
        L.tail->next = p;
        L.tail = p;
    }
}
void initList(List &L){
    L.head = NULL;
    L.tail = NULL;
}
void inputHash(Hashtable &h)
{
    cin>>h.n;
    int idx = 0;
    int temp;
    for(int i = 0;i < h.n;i ++){
        cin>>temp;
        idx = Hashfunc(temp,h.m);
        addTail(h.pl[idx],temp);
    }
}
void outputHash(Hashtable h){
    
}
int main(){
    ios::sync_with_stdio(0);
    Hashtable h;
    cin>>h.m>>h.LOAD;
    for(int i =0 ;i < h.m ;i ++){
        initList(h.pl[i]);
    }
    inputHash(h);
    outputHash(h);
    return 0;
}