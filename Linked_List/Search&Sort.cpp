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
    return temp;
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
void inputList(List &L,int n){
    for(int i = 0; i < n; i++){
        int x ; cin>>x; 
        AddTail(L,x);
    }
}
void Sort(Node* curr,Node *sorted){
    while(sorted){
        while(curr){
            if(curr->info < sorted->info){
                swap(curr->info,sorted->info);
            }
            curr = curr->next;
        }
        sorted = sorted->next;
    }
}
void SelectionSort(List &L){
    Node* curr = L.Head;
    Node* sorted = L.Head;
    Sort(curr,sorted);
}
int find(List L,int n, int key){
    
    int cnt = 0;
    Node* temp = L.Head;
    while(temp){
        if(temp->info == key){
            return cnt;
        }
        else {
            temp= temp->next;
            cnt++;
        }
    }
    return -1;
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
    int n;cin>>n;
    inputList(L,n);
    cout<<"Sorted List: ";
    SelectionSort(L);
    outputList(L);cout<<endl;
    int key; 
    cout<<"Find an element: ";
    cin>>key;
    cout<<endl;
    if(find(L,n,key) == -1){
        cout<<key<<" is not found"<<endl;
    }
    else {
        cout<<key<<" is found at the position "<<find(L,n,key)<<endl;
    }
    return 0;

}