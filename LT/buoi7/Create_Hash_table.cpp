/*###Begin banned keyword - each of the following line if appear in code will raise error. regex supported
define
include
using
###End banned keyword*/

#include <iostream>
#include <cstring>
#include <string>
#define MAX 1000
using namespace std;

//###INSERT CODE HERE -
struct node{
    int info;
    node* next;
};
struct Hash{
    int m;
    int n;
    node** bucket;
};
void initHash(Hash &H){
    H.bucket = new node*[H.m];
    for(int i =0 ;i < H.m ;i ++){
        H.bucket[i] = nullptr;
    }
}
int hashfunc(Hash H,int key){
    return key%H.m;
}
node* getnode(int x){
    node* temp = new node;
    temp->info = x;
    temp->next = nullptr;
    return temp;
}
void addHead(node *(&L), int x){
    node* temp = getnode(x);
        temp->next = L;
        L = temp;
}
node* findbefore(node* head, int x){
    
        node* pos = head;
        while(pos !=nullptr && pos->next !=nullptr){
            if(pos->next->info == x){
                return pos;
            }
        }
        return nullptr;
    
    return nullptr;
}
void addAfter(node* &q, int x){
    if(q){
        node* temp = getnode(x);
        temp->next = q->next;
        q->next = temp;
    }
}
void insertList(node *(&L),int x){
    node* p = L;
    node *q = nullptr;
    while(p != nullptr && x > p->info){
        q = p;
        p = p->next;
    }
    if(q==nullptr){
        addHead(L,x);
    }
    else addAfter(q,x);
}
void insertHash(Hash &H, int x){
    int idx = hashfunc(H,x);
    insertList(H.bucket[idx],x);
}
void printList(node* head){
    node* p = head;
    while (p)
    {
        cout<<p->info<<" ";
        p=p->next;
    }
    
}
void traverseAllHash(Hash H){
    for(int i = 0;i < H.m;i++){
        cout<<"Bucket "<<i<<": ";
        printList(H.bucket[i]);
        cout<<endl;
    }
}
int main()
{
    Hash H;
    cin>>H.m; // m la so dia chi co trong bang bam
    initHash(H); //khoi tao cac bucket

    int n,x;cin>>n; // n la so luong gia tri can phai luu tru
    for (int i = 1; i<=n;i++)
    {
        cin>>x;
        insertHash(H,x); // them 1 gia tri du lieu vao bang bam
    }
    cout<<"Created Hash:"<<endl;
    traverseAllHash(H); // Xuat toan bo cac bucket cua Bang bam

    return 0;
}

