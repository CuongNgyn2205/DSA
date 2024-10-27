/*###Begin banned keyword - each of the following line if appear in code will raise error. regex supported
define
include
###End banned keyword*/

#include <iostream>
using namespace std;


//###INSERT CODE HERE -

struct node{
    int info;
    node* next;
};
struct List{
    node* head, *tail;
};
void Init(List &L){
    L.head = L.tail = nullptr;
}
node* getnode(int x){
    node* temp = new node;
    temp->info = x;
    temp->next = nullptr;
    return temp;
}
void addTail(List &L, int z){
    node* p = getnode(z);
    if(L.head == nullptr){
        L.head = L.tail = p;
    }
    else{
        L.tail ->next = p;
        p->next = nullptr;
        L.tail = p;
    }

}
void addHead(List &L, int z){
    node * p = getnode(z);
    if(L.head == nullptr){
        L.head = L.tail = p;
    }
    else {
        p->next = L.head;
        L.head = p;
    }
}
void delHead(List &L ){
    node* p = L.head;
    if(L.head == nullptr){
        return ;
    }
    else{
        L.head = L.head->next;
        delete p;
    }
}
node* beforeTail(List L){
    node* pos = L.head;
    if(L.head == nullptr){
        return nullptr;
    }
    else if(L.head == L.tail){
        return L.head;
    }
    else {
        while(pos->next != L.tail){
            pos=pos->next;
        }
    }
    return pos;
}
void delTail(List &L){
    if(L.head == nullptr){
        return ;
    }
    else{
        node* p = beforeTail(L);
        if(p == L.head){
            delHead(L);
        }
        else {
            node * t = L.tail;
            p->next = nullptr;
            L.tail = p;
            delete t;
        }
    }
}
void inputList(List &L, int n){
    for(int i = 0;i < n;i ++){
        int x; cin>>x;
        addTail(L,x);
    }
}
void outputList(List L){
    node* pos = L.head;
    if(pos == nullptr){
        cout<<"List is empty";
    }
    while(pos){
        cout<<pos->info<<" ";
        pos = pos->next;
    }
}
int main(){
    List L;
    Init(L);
    int n;cin>>n;
    for(int i =0 ;i < n; i ++){
        char x,y;int z;
        cin>>x>>y;
        cin>>z;
        if(x == '+'){
            switch (y) {
                case 'H': {
                    addHead(L, z);
                    break;
                }
                case 'T': {
                    addTail(L, z);
                    break;
                }
                default:
                    break;
            }
        }
        else if(x == '-'){
            switch (y) {
                case 'H': {
                    delHead(L);
                    break;
                }
                case 'T': {
                    delTail(L);
                    break;
                }
                default:
                    break;
            }
        }
    }
    outputList(L);
    return 0;
}