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
        cout<<"List is empty";
        return;
    }
    node* pos = L.pHead;
    while(pos){
        cout<<pos->info<< " ";
        pos = pos->next; 
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
    return first;
}
int main()
{
    List L;
    L.pHead=L.pTail=NULL;
    int n; cin>>n;
    inputList(L,n);
    cout<<"Created List: "<<endl;
    outputList(L); // Neu ds rong thi xuat "List is empty"
    cout<<endl;

    int x, y; cin>>x>>y;
    node *p = swapData(L,x,y);
    /* Tim 2 node chua x va y,
    Hoan vi gia tri cua 2 node do,
    nghia la: Lien ket giua cac node khong thay doi, node ban dau chua x se doi lai la chua y
    Ham return node chua x ban dau, luc chua hoan vi*/

    cout<<"Updated List after swapping "<<x<<" and "<<y<<": "<<endl;
    outputList(L);
    cout<<endl;

    /* Kiem tra xem co that su hoan vi info cua 2 node khong
    Neu hoan vi info thi node chua x ban dau se doi lai chua y*/

    if(p) // co hoan vi
    {
        cout<<"At the address of "<<x<< ": ";
        cout<<p->info;
    }
    else cout<<"Can not swap";
    return 0;
}
