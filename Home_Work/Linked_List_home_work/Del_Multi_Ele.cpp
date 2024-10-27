/*###Begin banned keyword - each of the following line if appear in code will raise error. regex supported
define
include
###End banned keyword*/

#include <iostream>
using namespace std;


//###INSERT CODE HERE -


#include <iostream>
using namespace std;


//###INSERT CODE HERE -
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
    if(L.Head == NULL){
        L.Head = L.Tail = p;
    }
    else {
        L.Tail->next = p;
        L.Tail = p;
    }
}
Node* searchEle(List L, int key){
    Node*p = L.Head;
    while(p!=NULL){ 
        if(p->info == key){
            return p;
        }
        p=p->next;
    }
    return NULL;
}
void AddAfter(List &L, int x, int y){
    Node*p = searchEle(L,x);
    Node* temp = GetNode(y);
    if(p==NULL){
        addHead(L,y);
    }
    else{
        temp->next = p->next;
        p->next = temp;
        if(p==L.Tail){
            L.Tail = temp;
        }
    }
}
Node* searchBefore(List L, int x){
    Node * temp = L.Head;
    if(temp == nullptr || temp->next == nullptr){
        return nullptr;
    }
    while(temp->next){
        if(temp->next->info == x){
            return temp;
        }
        temp = temp->next;
    }
    return NULL;
}
void Delete_Head(List &L){
    if(L.Head == NULL){
        return;
    }
    else{
        Node* temp = L.Head;
        L.Head = L.Head->next;
        delete temp;
        if(L.Head == NULL){
            L.Tail = NULL;
        }
    }
}
Node* searchbeforeTail(List&L){
    Node* pos = L.Head;
    if(pos == nullptr || pos->next == nullptr){
        return nullptr;
    }
    while(pos->next != L.Tail){
        pos = pos->next;
    }
    return pos;
}
void Delete_Tail(List&L ){
    if(L.Head == nullptr){
        return ;
    }
    if(L.Head == L.Tail){
        delete L.Head;
        L.Head = L.Tail = nullptr;
    }
    else {
        Node* bef = searchbeforeTail(L);
        Node* end = L.Tail;
        if(bef != nullptr){
            bef->next = NULL;
            L.Tail = bef;
        }
        delete end;
    }
}
void Delete_Specific(List &L, int x){
    Node* searched = searchEle(L,x);
    if(searched == nullptr){
        return;
    }
    if(searched == L.Head){
        Delete_Head(L);
    }
    else if(searched == L.Tail){
        Delete_Tail(L);
    }
    else {
        Node* temp = searchBefore(L,x);
        if(temp != nullptr){
            temp->next = searched->next;
            delete searched;
        }
    }
}
void Delete_MultiEle(List&L, int x){
    while(1){
        Node* se = searchEle(L,x);
        if(se == nullptr){
            return;
        }
        else if(se == L.Head){
            Delete_Head(L);
        }
        else if(se == L.Tail){
            Delete_Tail(L);
        }
        else {
            Node*curr = searchBefore(L,x);
            if(curr){
                curr->next = se->next;
                se->next = nullptr;
                delete se;
            }
        }
    }
}
void Print(List L){
    Node *p = L.Head;
    if(p == NULL){
        cout<<"blank"<<endl;
    }
    else{
        while(p){
            cout<<p->info<<" ";
            p=p->next;
        }
    }
    cout<<endl;
}
int main(){
    List L;
    L.Head = L.Tail = NULL;
    int x;
    while(1){
        cin>>x;
        if(x == 6){ 
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
            case 3:{
                int y;
                cin>>y;
                Delete_Specific(L,y);
                break;
            }
            case 4:{
                int y;
                cin>>y;
                Delete_MultiEle(L,y);
                break;
            }
            case 5:{
                Delete_Head(L);break;
            }
            default:{
                break;
            }
        }
    }
    Print(L);
    return 0;
}