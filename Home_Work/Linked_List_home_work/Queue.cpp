#include<bits/stdc++.h>
using namespace std;
//init section
struct node{
    int val;
    node* next;
};
struct List{
    node* pHead,*pTail;
};
node* getnode(int x){
    node* temp = new node;
    temp->val = x;
    temp->next = nullptr;
    return temp;
}
node* searchEle(List L, int x){
    node* pos = L.pHead;
    while(pos){
        if(pos->val == x){
            return pos;
        }
        pos = pos->next;
    }
    return NULL;
}
node* searchbeforeEle(List L, int x){
    node* pos = L.pHead;
    while(pos && pos->next){
        if((pos->next)->val == x){
            return pos;
        }
        pos = pos->next;
    }
    return NULL;
}
node* searchBeforeTail(List L){
    node* pos = L.pHead;
    while(pos){
        if(pos->next == L.pTail){
            return pos;
        }
        pos = pos->next;
    }
    return NULL;
}
void add_Tail(List &L, int x){
    node* temp = getnode(x);
    if(L.pHead == NULL){
        L.pHead = L.pTail = temp;
    }
    else{
        L.pTail->next = temp;
        L.pTail = temp;
    }
}
void add_Head(List &L, int x){
    node* temp = getnode(x);
    if(L.pHead == NULL){
        L.pHead = L.pTail = temp;
    }
    else{
        temp->next = L.pHead;
        L.pHead = temp;
    }
}
void del_Head(List &L){
    if(L.pHead == NULL){
        return;
    }
    else if(L.pHead == L.pTail){
        L.pHead = L.pTail = NULL;
    }
    else{
        node* head = L.pHead;
        L.pHead = L.pHead->next;
        delete head;
    }
}

void del_Tail(List &L){
    if(L.pHead == NULL){
        return;
    }
    else if(L.pHead == L.pTail){
        return;
    }
    else{
        node*beforetail = searchBeforeTail(L);
        node*Tail = L.pTail;
        if(beforetail){
            beforetail->next = NULL;
            L.pTail = beforetail;
            delete Tail;
        }
        
    }
}
void del_Specific(List &L, int x){
    node* curr = searchEle(L,x);
    node* prev = searchbeforeEle(L,x);
    if(L.pHead == NULL){
        return;
    }
    else if(curr == L.pHead){
        del_Head(L);
    }
    else if( curr == L.pTail){
        del_Tail(L);
    }
    else{
        if(prev && curr){
            prev->next = curr->next;
            curr->next = NULL ;
            delete curr;
        }

    }
}
void Change(List &L,int x){
    node* prev = searchbeforeEle(L,x);
    node* curr = searchEle(L,x);
    if(curr == NULL || curr==L.pHead){
        return;
    }
    if(prev){
        prev->next=curr->next;
    }
    if(curr == L.pTail){
        L.pTail = prev;
    }
    curr->next = L.pHead;
    L.pHead = curr;
}
void inputList(List &L,int n){
    int temp = 1;
    for(int i =0 ;i < n;i ++){
        add_Tail(L,temp);
        temp++;
    }
}
void outputList(List L){
    node* pos = L.pHead;
    while(pos){
        cout<<pos->val<<" ";
        pos = pos->next;
    }
}
int main(){
    queue<int> list;
    
    int n,m;
    cin>>n>>m;
    inputList(L,n);
    for(int i = 0 ;i < m; i++){
        int temp;
        cin>>temp;
        Change(L,temp);
    }
    outputList(L);
    return 0;
}