/*###Begin banned keyword - each of the following line if appear in code will raise error. regex supported
define
include
###End banned keyword*/

#include <iostream>
using namespace std;


//###INSERT CODE HERE -
struct Node{
    int info;
    Node* next;
};
struct List{
    Node* Head, *Tail;
};
Node* GetNode(int x){
    Node * temp = new Node;
    temp->info = x;
    temp->next = NULL;
}
void AddTail(List &L, int x){
    Node* temp = GetNode(x);
    if(L.Head == NULL){
        L.Head = L.Tail = temp;
    }
    else {
        L.Tail ->next = temp;
        L.Tail = temp;
    }
}
void inputList(List &L){
    int n;cin>>n;
    for(int i = 0; i < n; i++){
        int x ; cin>>x; 
        AddTail(L,x);
    }
}
void SelectionSort(List &L){
    Node *i = L.Head;
    Node *j =L.Head;
    while(i!= NULL){
        Node max = 
        while(j!=NULL){
            if(j<i){
                
            }

        }
    }
}
void outputList(List &L){
    Node* p = L.Head;
    while(p != NULL){
        cout<<p->info<<" ";
    }
    cout<<endl;
}
int main(){
    List L;
    L.Head = L.Tail = NULL;
    inputList(L);
    return 0;

}