/*###Begin banned keyword - each of the following line if appear in code will raise error. regex supported
###End banned keyword*/
#include<iostream>
using namespace std;
struct node
{
    int info;
    node* next;
};
struct List
{
    node *head, *tail;

};
struct Hash
{
    int m;
    int n;
    float load;
    List *pL; //con tro quan ly 1 mang chua cac List
};

//###INSERT CODE HERE -
void initList(List &L){
    L.head = L.tail = nullptr;
}
void Inithash(Hash &H){
    H.pL = new List[H.m];
    for(int i =0 ;i < H.m;i ++){
        initList(H.pL[i]);
    }
    H.n = 0;
}
int hashfunc(Hash H,int x){
    return x % H.m;
}
node* getnode(int x){
    node* temp = new node;
    temp->next = nullptr;
    temp->info = x;
    return temp;
}
void insertList(List &L,int x){
    node* temp = getnode(x);
    if(L.head == nullptr){
        L.head = L.tail = temp;
    }
    else {
        L.tail->next = temp;
        L.tail = temp;
    }
}
void insertHash(Hash &H,int x){
    if(double(H.n + 1)/H.m > H.load){
        return;
    }
    else{
        int idx=hashfunc(H,x);
        insertList(H.pL[idx],x);
        H.n++;
    }
}
void inputHash(Hash &H,int n){
    Inithash(H);
    for(int i = 0;i < n;i ++){
        int x;
        cin>>x;
        insertHash(H,x);
    }
}
void printHash(Hash H){
    for(int i = 0;i < H.m;i ++){
        cout<<"List "<<i<<": ";
        node* pos = H.pL[i].head;
        while (pos)
        {
            cout<<pos->info<<" ";
            pos = pos->next;
        }
        cout<<endl;
    }
}
int searchList(List L, int x){
    node * pos = L.head;
    int cnt = 0;
    while(pos){
        cnt++;
        if(pos->info == x){
            return cnt;
        }
        pos = pos->next;
    }
    return 0;
}
void searchHash(Hash H, int key){
    int idx = hashfunc(H,key);
    int count = searchList(H.pL[idx],key);
    if(count>0){
        cout<<count<<endl;
    }
    else{
        cout<<"KHONG"<<endl;
    }
    return;
}
int main()
{
    Hash H;  cin>>H.m>>H.load;
    int n;cin>>n;
    inputHash(H,n);
    printHash(H);
    int nkey,key;cin>>nkey;

    for(int i=0;i<nkey;i++)
    {
        cin>>key;
        searchHash(H,key);
    }
    return 0;
}
