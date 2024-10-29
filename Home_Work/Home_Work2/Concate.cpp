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
struct Node{
    int val;
    Node* next;
};

struct List{
    Node *head, *tail;
};

void list_initializing(List &l){
    l.head = l.tail = NULL;
}

void Init(List &L){
    L.head = L.tail = nullptr;
}
Node* Getnode(int x){
    Node * temp = new Node;
    temp->val = x;
    temp->next = NULL;
    return temp;
}
void add_tail(List &L, int x){
    Node* temp = Getnode(x);
    if(L.head == NULL){
        L.head = L.tail = temp;
    }
    else {
        L.tail ->next = temp;
        L.tail = temp;
    }
}
void inputList(List &L,int n){
    for(int i = 0; i < n; i++){
        int x ; cin>>x; 
        add_tail(L,x);
    }
}
void outputList(List L){
    if(L.head == nullptr){
        cout<<"List is empty"<<endl;
        return;
    }
    Node* pos = L.head;
    while(pos){
        cout<<pos->val<< " ";
        pos = pos->next; 
    }
}

void copy(List &l, List &l2){
    Node* pos = l.head;
    while(pos){
        add_tail(l2,pos->val);
        pos=pos->next;
    }
    
}
void concate(List &l1, List& l2){
    if(l1.head == nullptr){
        l1.head = l2.head;
        l1.tail = l2.tail;
    }
    else if(l2.head == nullptr){
        return;
    }
    else {
        l1.tail->next = l2.head;
        l1.tail = l2.tail;
    }
    
}
int main()
{
    List L1, L2;
    Init(L1);Init(L2);

    int n; cin>>n;
    inputList(L1,n);
    cout<<"Created 1st List: "<<endl;
    outputList(L1);
    cout<<endl;

    cin>>n;
    inputList(L2,n);
    cout<<"Created 2nd List: "<<endl;
    outputList(L2);
    cout<<endl;

    concate(L1,L2); // Noi L2 vao L1
    cout<<"Updated L1: "<<endl;
    outputList(L1);

    return 0;
}
