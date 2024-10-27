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
void addTail(List &L, node* p){
    if(L.head == nullptr){
        L.head = L.tail = p;
    }
    else{
        L.tail ->next = p;
        p->next = nullptr;
        L.tail = p;
    }

}
void inputList(List &L, int n){
    for(int i = 0;i < n;i ++){
        int x; cin>>x;
        node* p = getnode(x);
        addTail(L,p);
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
node* findMax(List L){
    node* max = L.head;
    node* pos = L.head;
    if(pos == nullptr){
        cout<<"List is empty";
    }
    while(pos){
        if(pos->info > max->info){
            max = pos;
        }
        else{
            pos=pos->next;
        }
    }
    return max;
}
int main()
{
    List L;
    Init(L);
    int n; cout<<"Enter a number: "; cin>>n;
    cout<<"\nEnter a sequence of "<<n<<" numbers: ";
    inputList(L,n);
    cout<<"\nThe created Linked List: ";
    outputList(L);


    cout<<"\nThe maximum value: ";
    node *p = findMax(L);
    if(p) cout<<p->info;

    return 0;
}
