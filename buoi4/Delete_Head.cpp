/*###Begin banned keyword - each of the following line if appear in code will raise error. regex supported
define
include
###End banned keyword*/

#include <iostream>
using namespace std;


//###INSERT CODE HERE -
using namespace std;
struct Node{
    int info;
    Node *next;
};
struct List{
    Node *Head, *Tail;
};  
Node* GetNode(int x){
    Node *p = new Node;
    p->info = x;
    p->next = NULL;
    return p;
};
void addHead(List &L, int x){
    Node *p = GetNode(x);
    if(L.Head == NULL){
        L.Head = L.Tail = p;
    }
    else{
        p->next = L.Head;
        L.Head = p;
    }
}
void addTail(List &L, int x){
    Node *p = GetNode(x);
    if(L.Tail == NULL){
        L.Head = L.Tail = p;
    }
    else {
        L.Tail->next = p;
        L.Tail = p;
    }
}
Node* searchEle(List &L, int key){
    Node* p = L.Head;
    while(p!=NULL){
        if(p->info == key){
            return p;
        }
        p=p->next;
    }
    return NULL;
}
void AddAfter(List &L, int key, int x){
    Node*curr = searchEle(L,key);
    Node* temp = GetNode(x);
    if(curr == NULL){
        addHead(L,x);
    }
    else {
        temp->next = curr->next;
        curr->next = temp;
    }
}
void Delete_Head(List &L){
    Node* p = L.Head;
    L.Head = L.Head->next;
    p->next = NULL;
}
void Print(List L){
    Node *p = L.Head;
    if(p == NULL){
        cout<<"blank"<<endl;
    }
    while(p){
        cout<<p->info <<" ";
        p = p ->next;
    }
    cout<<endl;
}
int main(){
    List L;
    L.Head = L.Tail = NULL;
    int x;
    while(1){
        cin>>x;
        if(x==6){
            break;
        }
        switch(x){
            case 0:{
                int y;
                cin>>y;
                addHead(L,y);
                break;
            }
            case 1:{
                int y;cin>>y;
                addTail(L,y);
                break;
            }
            case 2:{
                int y,z;
                cin>>y>>z;
                AddAfter(L,y,z);
                break;
            }
            case 5:{
                Delete_Head(L);
                break;
            }
        }
    }
    Print(L);
    return 0;
}