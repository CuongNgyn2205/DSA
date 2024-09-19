/*###Begin banned keyword - each of the following line if appear in code will raise error. regex supported
define
include
[
###End banned keyword*/

#include <iostream>
using namespace std;


//###INSERT CODE HERE -
struct Node{
    int info;
    Node *next;
};
struct List{
    Node *Head,*Tail;
};
Node *GetNode(int x){
    Node* p = new Node;
    p->info =x ;
    p->next = NULL;
    return p;
};
void addHead(List &L,int x){
    Node *p = GetNode(x);
    if(L.Head == NULL){
        L.Head = L.Tail= p;
    }
    else {
        p->next = L.Head;
        L.Head = p;
    }
}
void addTail(List &L, int x){
    Node*p = GetNode(x);
    if(L.Tail == NULL){
        L.Head = L.Tail = p;
    }
    else {
       L.Tail->next = p;
       L.Tail = p;
    }
}
void Print(List L){
    Node*p;
    p=L.Head;
    while(p!=NULL)
    {
        cout<<p->info<<" ";  
        p=p->next;
    }
}
int main(){
    List L;
    L.Head = L.Tail = NULL;
    while(1){
        int x;
        cin>>x;
        if(x== 3){
            break;
        }
        int y;cin>>y;
        if(x == 0){
            addHead(L,y);
        }
        else {
            addTail(L,y);
        }
    }
    Print(L);
    return 0;
}