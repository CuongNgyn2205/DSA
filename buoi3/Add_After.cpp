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
Node* searchEle(List L, int x){
    Node *k = L.Head;
    while(k!=NULL){
        if(k->info == x){
            return k;
        }
        k = k->next;
    }
    return L.Head;
}
void addAfter(List &L,int x, int y){
    Node *k = searchEle(L,x);
    if(k->next == NULL){
        addTail(L,y);
    }
    else if(k == L.Head){
        addHead(L,y);
    }
    else {
        Node *new_node = GetNode (y);
        new_node->next = k->next;
        k->next = new_node;
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
        switch(x){
            case 0: {
                int y;cin>>y;addHead(L,y);break;
            }
            case 1:{
                int y; cin>>y; addTail(L,y);break;
            }
            case 2:{
                int y,z;
                cin>>y>>z;
                addAfter(L,y,z);
                break;
            }
        }
    }
    Print(L);
    return 0;
}