#include<bits/stdc++.h>
using namespace std;
struct Node{
    int info;
    Node *next,*prev;
};
Node* GetNode(int x){
    Node* temp = new Node;
    temp->info = x;
    temp->next = temp->prev = NULL;
    return temp;
};
struct List{
    Node* Head, *Tail;
};
void addHead(List &L, int x){
    Node *temp = GetNode(x);
    if(L.Head == NULL){
        L.Head = L.Tail = temp;
    }
    else {
        temp->next = L.Head;
        temp->prev = NULL;
        L.Head->prev = temp;
        temp = L.Head;
    }
}
void addTail(List& L, int x){
    Node* temp = GetNode(x);
    if(L.Head == NULL){
        L.Head = L.Tail = temp;
    }
    else {
        L.Tail->next = temp;
        temp->prev = L.Tail;
        temp->next = NULL;
        temp = L.Tail;
    }
}
void Print(List L){
    Node* index = L.Head;
    while(index != NULL){
        cout<<index->info<<" ";
        index= index->next;
    }
    
}
int main(){
    List L;
    L.Head = L.Tail = NULL;
    int x;
    cin>>x;
    while(1){
        switch(x){
            case 0: {
                int y; cin>>y;
                addHead(L,y);
                break;
            }
            case 1:{
                int y; cin>>y;
                addTail(L,y);
                break;
            }
        }
    }
    Print(L);
}