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
    node* pHead, *pTail;
};
void Init(List &L){
    L.pHead = L.pTail = nullptr;
}
node* Getnode(int x){
    node * temp = new node;
    temp->info = x;
    temp->next = NULL;
    return temp;
}
void AddpTail(List &L, int x){
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
        AddpTail(L,x);
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
node* findMiddle(List L){
    if(L.pHead == nullptr){
        return nullptr;
    }
    int cnt = 0;
    node* pos = L.pHead;
    node* temp = L.pHead;
    while(pos){
        pos= pos->next;
        cnt++;
    }
    cnt /= 2;
    delete pos;
    for(int i=0;i < cnt;i ++){
        temp=temp->next;
    }
    return temp;
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

    node *p=findMiddle(L); //Neu so phan tu chan thi co 2 phan tu chinh giua, chi xuat phan tu chinh giua thu 2
    if(p)cout<<"The middle element is "<<p->info;

    return 0;
}
