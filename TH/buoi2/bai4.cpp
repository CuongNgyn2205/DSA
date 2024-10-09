/*###Begin banned keyword - each of the following line if appear in code will raise error. regex supported
define
include
using
[
]
###End banned keyword*/

#include <iostream>
using namespace std;

/*Cach 1: Khi da cai dat List roi, dinh nghia Stack dua tren List
struct Stack
{
	List L;
};

Cach 2: Cai dat lai Stack tu dau, giong nhu List
struct node
{
    int info;
    node *next;
};
struct Stack
{
    node *pHead; // pTail khong co cung duoc

};*/

//###INSERT CODE HERE -
struct node
{
    int info;
    node *next;
};
struct Stack
{
    node *pHead;

};
void Init(Stack &S){
    S.pHead = NULL;
}
node* GetNode(int x){
    node* p = new node;
    p->info = x;
    p->next = NULL;
    return p;
}
void Push(Stack& S, int x){
    node* temp = GetNode(x);
    if(S.pHead == NULL){
        S.pHead = temp;
    }
    else{
        temp->next = S.pHead;
        S.pHead = temp;
    }
}
void DecimaltoBinary1(int n, Stack &S){
    while(n>0){
        Push(S,n%2);
        n /= 2;
    }
}
void printStack(Stack S){
    node* pos = S.pHead;
    if(S.pHead == NULL){
        cout<<0;
    }
    while(pos){
        cout<<pos->info;
        pos = pos->next;
    }
}
int main()
{
    Stack S;Init(S);
    int n,x;
    cin>>n;
    DecimaltoBinary1(n,S);
    printStack(S);
    return 0;
}

