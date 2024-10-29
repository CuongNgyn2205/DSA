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
void init(DList &L){
    L.pHead = L.pTail = nullptr;
}
DNode* getnode(int x){
    DNode* p = new DNode;
    p->info = x;
    p->pNext = p->pPrev = nullptr;
    return p;
}
void addTail(DList &L,int x){
    DNode* temp = getnode(x);
    if(L.pHead == nullptr){
        L.pHead = L.pTail = temp;
        return;
    }
    L.pTail->pNext = temp;
    L.pTail = temp;
}
void addHead(DList &L, int x){
    DNode* temp = getnode(x);
    if(L.pHead == nullptr){
        L.pHead = L.pTail = temp;
    }
    temp->pNext = L.pHead;
    L.pHead->pPrev = temp;
    temp->pPrev = nullptr;
    L.pHead = temp;
}
DNode* find(DList L, int x){
    DNode* pos = L.pHead;
    while(pos){
        if(pos->info == x){
            return pos;
        }
        pos = pos->pNext;
    }
    return nullptr;
}
void addBefore(DList &L,int x, int y){
    DNode* curr = find(L,x);
    DNode* before = getnode(y);
    if(curr == NULL){
        cout<<"\nCan't find the value"<<x<<endl;
    }
    else if(curr == L.pHead){
        addHead(L,y);
    }
    else{
        before->pNext = curr;
        before->pPrev = curr->pPrev;
        curr->pPrev->pNext = before;
        curr->pPrev = before;
    }
}
void addAfter(DList &L,int x, int y){
    DNode* curr = find(L,x);
    DNode* after = getnode(y);
    if(curr == NULL){
        cout<<"\nCan't find the value"<<x<<endl;
    }
    else if(curr == L.pTail){
        addTail(L,y);
    }
    else{
        after->pPrev = curr;
        after->pNext = curr->pNext;
        curr->pNext = after;
        curr->pNext->pPrev = after;
    }
}
void createList(DList &L){
    int temp;
    while(1){
        cin>>temp;
        if(temp == -1){
            return;
        }
        addTail(L,temp);
    }
}
void printList(DList L){
    DNode* temp = L.pHead;
    while(temp){
        cout<<temp->info<<" ";
        temp = temp->pNext;
    }
}
void addAfterMulti(DList &L, int x, int y){
    DNode* found = L.pHead;
    while(found){
        if(found->info == x){
            DNode* after = getnode(y);
            after->pNext = found->pNext;
            after->pPrev = found;
            if(found == L.pHead){
                
            }
        }
        found = found->pNext;
    }
}
void addBeforeMulti(DList &L, int x, int y){
    DNode* found = L.pHead;
    while(found){
        if(found->info == x){
            
        }
        found = found->pNext;
    }
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
        case 7:
            cout<<"\nEnter two numbers: ";
            cin>>x>>y;
            addAfterMulti(L,x,y);
            break;
        case 8:
            cout<<"\nEnter two numbers: ";
            cin>>x>>y;
            addBeforeMulti(L,x,y);
            break;
        case 20:
            cout<<"\nGOOD BYE";
            return 0;

        }
    }

	return 0;
}
