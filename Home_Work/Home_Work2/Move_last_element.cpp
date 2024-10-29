/*###Begin banned keyword - each of the following line if appear in code will raise error. regex supported
define
include
using
###End banned keyword*/

#include <iostream>
#include <cstring>
#include <string>
using namespace std;

//###INSERT CODE HERE -
struct node{
    int info;
    node* next;
};

struct List{
    node *pHead, *pTail;
};

void list_initializing(List &l){
    l.pHead = l.pTail = NULL;
}

void Init(List &L){
    L.pHead = L.pTail = nullptr;
}
node* Getnode(int x){
    node * temp = new node;
    temp->info = x;
    temp->next = NULL;
    return temp;
}
void add_pTail(List &L, int x){
    node* temp = Getnode(x);
    if(L.pHead == NULL){
        L.pHead = L.pTail = temp;
    }
    else {
        L.pTail ->next = temp;
        L.pTail = temp;
    }
}
void inputList(List &L,int n){
    for(int i = 0; i < n; i++){
        int x ; cin>>x; 
        add_pTail(L,x);
    }
}
void outputList(List L){
    if(L.pHead == nullptr){
        cout<<"List is empty"<<endl;
        return;
    }
    node* pos = L.pHead;
    while(pos){
        cout<<pos->info<< " ";
        pos = pos->next; 
    }
}

void copy(List &l, List &l2){
    node* pos = l.pHead;
    while(pos){
        add_pTail(l2,pos->info);
        pos=pos->next;
    }
    
}
void concate(List &l1, List& l2){
    if(l1.pHead == nullptr){
        l1.pHead = l2.pHead;
        l1.pTail = l2.pTail;
    }
    else if(l2.pHead == nullptr){
        return;
    }
    else {
        l1.pTail->next = l2.pHead;
        l1.pTail = l2.pTail;
    }
    
}
node* find(List L,int x){
    node * pos = L.pHead;
    while(pos){
        if(pos->info == x){
            return pos;
        }
        pos = pos->next;
    }
    return nullptr;
}
node * swapData(List &L, int x, int y){
    if(L.pHead == nullptr){
        return nullptr;
    }
    int temp;
    node* first = find(L,x);
    node* second = find(L,y);
    if(first == nullptr || second == nullptr){
        return nullptr;
    }
    temp = first->info;
    first->info = second->info;
    second->info = temp;
    return L.pHead;
}
void addHead(List&L , int x){
    node* temp = Getnode(x);
    if(L.pHead == NULL){
        L.pHead = L.pTail = temp;
    }
    else{
        temp->next = L.pHead;
        L.pHead = temp;
    }
}
node* findbefore(List L){
    if(L.pHead == nullptr){
        return nullptr;
    }
    node* pos = L.pHead;
    while(pos){
        if(pos->next == L.pTail){
            return pos;
        }
        pos = pos->next;
    }
    return nullptr;
}
void delTail(List &L){
    if(L.pHead == nullptr){
        return ;
    }
    else if(L.pHead == L.pTail){
        L.pHead = L.pTail = nullptr;
    }
    else {
        node* temp = findbefore(L);
        temp->next = nullptr;
        L.pTail = temp;
    }
    
}
void moveLastToFront(List &L){
    if(L.pHead == nullptr){
        return ;
    }
    int temp = L.pTail->info;
    addHead(L,temp);
    delTail(L);
}
int main()
{
    List L;
    L.pHead=L.pTail=NULL;
    int n; cin>>n;
    inputList(L,n);
    cout<<"Created List: "<<endl;
    outputList(L);
    cout<<endl;

    moveLastToFront(L); //di chuyen node cuoi ve dau danh sach
    cout<<"Updated List after moving the last element to front of L: "<<endl;
    outputList(L);
    return 0;
}
