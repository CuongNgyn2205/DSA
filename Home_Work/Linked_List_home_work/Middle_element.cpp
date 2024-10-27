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
node* getnode(int x){
    node* temp = new node;
    temp->info = x;
    temp->next = nullptr;
    return temp;
}
void addTail(List &L, node* p){
    if(L.pHead == nullptr){
        L.pHead = L.pTail = p;
    }
    else{
        L.pTail ->next = p;
        p->next = nullptr;
        L.pTail = p;
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
    node* pos = L.pHead;
    if(pos == nullptr){
        cout<<"List is empty";
    }
    while(pos){
        cout<<pos->info<<" ";
        pos = pos->next;
    }
}
node* findMax(List L){
    node* max = L.pHead;
    node* pos = L.pHead;
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
node* findMiddle(List L){
    node* temp = L.pHead;
    int cnt = 0;
    while(temp){
        temp= temp->next;
        cnt++;
    }
    node* pos = L.pHead;
    int k =0;
    if(cnt%2 == 0){
        cnt = cnt/2 + 1;
    }
    else{
        cnt/=2;
    }
    while(pos){
        if(k == cnt){
            break;
        }
        else{
            pos= pos->next;
        }
    }
    return pos;
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
