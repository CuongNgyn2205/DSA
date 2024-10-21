/*###Begin banned keyword - each of the following line if appear in code will raise error. regex supported
define
include
struct
classs
###End banned keyword*/

#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

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

//###INSERT CODE HERE -
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
int main()
{
    cin.tie(NULL);
    std::ios_base::sync_with_stdio(false);

    List l; list_initializing(l);
    //Read list
    int x;
    do{
        cin >> x;
        add_tail(l, x);
    } while(x != 0);

    List l2; list_initializing(l2);
    copy(l, l2);

    Node*p = l.head, *q = l2.head;
    while(p != NULL){
    	if (p == q || p->val != q->val) cout << "WRONG";
    	cout << p->val << endl;
    	p = p->next;
    	q = q->next;
    }
    return 0;
}
