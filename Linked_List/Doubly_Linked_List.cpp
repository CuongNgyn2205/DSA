/*###Begin banned keyword - each of the following line if appear in code will raise error. regex supported
define
include
using
###End banned keyword*/

#include  <iostream>
using namespace std;

struct DNode
{
	int info;
	DNode *pNext, *pPrev;
};

struct DList
{
	DNode *pHead, *pTail;
};

//###INSERT CODE HERE -
DNode* GetNode(int x){
    DNode *p = new DNode;
    p->info = x;
    p->pNext = NULL;
    p->pPrev = NULL;
    return p;
}
void init(DList &L){
    L.pHead = NULL;
    L.pTail = NULL;
}
void addTail(DList &L, int x){
    DNode * p = GetNode(x);
    if(L.pHead == NULL){
        L.pHead = L.pTail = p;
    }
    else {
        L.pTail->pNext = p;
        p->pPrev = L.pTail;
        p->pNext = NULL;
        L.pTail = p;
    }
}
void addHead(DList &L, int x){
    DNode * p = GetNode(x);
    if(L.pHead == NULL){
        L.pHead = L.pTail = p;
    }
    else {
        p->pNext = L.pHead;
        p->pPrev = NULL;
        L.pHead ->pPrev = p;
        L.pHead = p;
        
    }
}
void createList(DList &L){
    int x;
    while(1){
        cin>>x;
        if(x==-1){
            break;
        }
        addTail(L,x);
    }
}
DNode* searchEle(DList L, int key){
    DNode* pos = L.pHead;
    while(pos){
        if(pos->info == key){
            return pos;
        }
        pos=pos->pNext;
    }
    return NULL;
}
void addBefore(DList &L,int key,int y){
    DNode *temp = searchEle(L,key);
    DNode * new_node = GetNode(y);
    if(temp == NULL){
        cout<<"\nCan't find the value "<<key<<endl;
        delete new_node;
    }
    else if(temp == L.pHead){
        addHead(L,y);
    }
    else {
        new_node ->pNext = temp;
        new_node ->pPrev = temp->pPrev;
        temp->pPrev->pNext = new_node;
        temp->pPrev = new_node;
    }
}
void addAfter(DList &L,int key,int y){
    DNode * temp = searchEle(L,key);
    DNode* new_node = GetNode(y);
    if(temp == NULL){
        cout<<"\nCan't find the value "<<key<<endl;
        delete new_node;
    }
    else if(temp == L.pTail) {
        addTail(L,y);
    }
    else {
        new_node->pPrev = temp;
        new_node->pNext = temp->pNext;
        temp->pNext->pPrev = new_node;
        temp->pNext = new_node;
    }
}
void printList(DList L){
    DNode *p = L.pHead;
    if(p == NULL){
        cout<<"List is empty"<<endl;
    }
    else {
        while(p){
        cout<<p->info<<" ";
        p= p->pNext;

        }
    }
    cout<<endl;
    
}
int main()
{
	DList L;
	init(L);
	int x,y,choice;

	cout<<"MENU:";
    cout<<"\n1. Create a DList";
    cout<<"\n2. Print the DList";
    cout<<"\n3. Insert a value at the front";
    cout<<"\n4. Insert a value at the end";
    cout<<"\n5. Insert a value after a given value (only for the first value found)";
    cout<<"\n6. Insert a value before a given value (only for the first value found)";
    cout<<"\n7. Insert a value after a given value (for all the same values)";
    cout<<"\n8. Insert a value before a given value (for all the same values)";
    cout<<"\n20. Exit"<<endl;

	while(true)
    {
        cout<<"\n\t\tPLEASE SELECT YOUR CHOICE: ";
        cin>>choice;
        switch(choice)
        {
        case 1:
            cout<<"\nEnter your positive integers until you enter -1 to finish: ";
            createList(L);
            break;
        case 2:
            cout<<"\nYour current DList: ";
            printList(L);
            break;
        case 3:
            cout<<"\nEnter a number: ";
            cin>>x;
            addHead(L,x);
            break;
        case 4:
            cout<<"\nEnter a number: ";
            cin>>x;
            addTail(L,x);
            break;
        case 5:
            cout<<"\nEnter two numbers: ";
            cin>>x>>y;
            addAfter(L,x,y);
            break;
        case 6:
            cout<<"\nEnter two numbers: ";
            cin>>x>>y;
            addBefore(L,x,y);
            break;
        case 20:
            cout<<"\nGOOD BYE";
            return 0;

        }
    }

	return 0;
}
