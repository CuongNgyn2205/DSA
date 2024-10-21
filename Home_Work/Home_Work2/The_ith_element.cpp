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
    node* Head, *Tail;
};
void Init(List &L){
    L.Head = L.Tail = nullptr;
}
node* Getnode(int x){
    node * temp = new node;
    temp->info = x;
    temp->next = NULL;
    return temp;
}
void AddTail(List &L, int x){
    node* temp = Getnode(x);
    if(L.Head == NULL){
        L.Head = L.Tail = temp;
    }
    else {
        L.Tail ->next = temp;
        L.Tail = temp;
    }
}
void inputList(List &L,int n){
    for(int i = 0; i < n; i++){
        int x ; cin>>x; 
        AddTail(L,x);
    }
}
void outputList(List L){
    if(L.Head == nullptr){
        cout<<"List is empty"<<endl;
        return;
    }
    node* pos = L.Head;
    while(pos){
        cout<<pos->info<< " ";
        pos = pos->next; 
    }
}
node* findElementFromEnd(List L, int i){
    node* current1 = L.Head;
    node* current2 = L.Head;
    int num = 0;
    while(current1 != nullptr)
    {
        num++;
        current1 = current1->next;
    }
    if(L.Head == nullptr ){
        cout<<"List is empty"<<endl;
        return nullptr;
    }
    else if(i < 0 || i > num){
        cout<<"The index is invalid";
        return nullptr;
    }
    else{
        int NumOfIterations = num - i;
        for (int i = 1; i <= NumOfIterations; i++)
            current2 = current2->next;
    }
    return current2;
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

    int i; cout<<"\nEnter a number: "; cin>>i;
    cout<<"\nThe element at index "<<i<<" (from the end of L): ";
    node *p = findElementFromEnd(L,i);
    if(p) cout<<p->info;


    return 0;
}
