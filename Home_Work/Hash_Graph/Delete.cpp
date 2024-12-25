/*###Begin banned keyword - each of the following line if appear in code will raise error. regex supported
define
include
###End banned keyword*/

#include <iostream>
#include <string>

#define LOAD 0.7
using namespace std;

struct Hocsinh {
    int Maso;
    string Hoten;
    int Namsinh;
    bool Gioitinh;
    double TBK;
};

struct Node {
    Hocsinh data;
    Node *next;
};

struct List {
    Node * head, *tail;
};

struct Hashtable {
    int M; // Kich thuoc bang bam
    int n; // so phan tu trong bang bam
    List *table;
};

//###INSERT CODE HERE -
Node* Getnode(Hocsinh hs){
    Node* p = new Node;
    p->data = hs;
    p->next = NULL;
    return p;
}
void initList(List &l){
    l.head = l.tail = NULL;
}
void CreateHashtable(Hashtable &h, int m) {
    h.M = m;
    h.n = 0;
    h.table = new List[m];
    for (int i = 0; i < m; i++) {
        initList(h.table[i]);
    }
}
void AddTail(List &l,Hocsinh hs){
    Node* p = Getnode(hs);
    if(l.head == NULL){
        l.head = l.tail = p;
    }
    else{
        l.tail->next = p;
        l.tail = p;
    }
}
void PrintHashtable(Hashtable h){
    Hocsinh hs;
    for (int i = 0; i < h.M; i++) {
        Node *p = h.table[i].head;
        while (p != NULL) {
            hs = p->data;
            cout << '[' << hs.Maso << ",  " << hs.Hoten << "  , " << hs.Gioitinh << ", " << hs.Namsinh << ", " << hs.TBK << "] ";
            p = p->next;
        }
        cout << endl;
    }
}
void DeleteHashtable(Hashtable &h) {
    Node* p = NULL;
    Node *q = NULL;
    for (int i = 0; i < h.M; i++) {
        p = h.table[i].head;
        while (p != NULL) {
            q = p;
            p = p->next;
            delete q;
        }
    }
    delete[] h.table;
    h.table = NULL;
    h.M = 0;
    h.n = 0;
}
void Input(Hocsinh &x) {
    cin >> x.Maso;
    getline(cin>>ws, x.Hoten);
    cin >> x.Gioitinh;
    cin >> x.Namsinh;
    cin >> x.TBK;
}
List SearchList(Hashtable h, int k){
    Node* p = NULL;
    for(int i = 0;i < h.M;i ++){
        p = h.table[i].head;
        while(p){
            if(p->data.Maso == k){
                return h.table[i];
            }
            else
            p = p->next;
        }
    }
    List emp;
    emp.head = emp.tail = NULL;
    return emp;
}
Node* Search(Hashtable h, int k){
    Node *find = NULL;
    for(int i =0 ;i < h.M;i ++){
        find = h.table[i].head;
        while(find){
            if(find->data.Maso == k){
                return find;
            }
            find = find->next;
        }
    }
    return NULL;
}
void Del_Tail(List &l){
    if(l.head == NULL){
        return;
    }
    if(l.head == l.tail){
        delete l.head;
        l.head = l.tail = NULL;
    } else {
        Node* before = l.head;
        while(before->next != l.tail){
            before = before->next;
        }
        delete l.tail;
        before->next = NULL;
        l.tail = before;
    }
}
void Del_Head(List &p){
    if (p.head == NULL) {
        return;
    } else {
        Node* temp = p.head;
        p.head = p.head->next;
        delete temp;
        if (p.head == NULL) {
            p.tail = NULL;
        }
    }
}
void Del_SpecialPos(List &l, int k){
    if(l.head == NULL){
        return;
    }
    if(l.head->data.Maso == k){
        Del_Head(l);
        return;
    }
    Node* before = l.head;
    while(before->next != NULL && before->next->data.Maso != k){
        before = before->next;
    }
    if(before->next != NULL){
        Node* curr = before->next;
        before->next = curr->next;
        if(curr == l.tail){
            l.tail = before;
        }
        delete curr;
    }
}
int Delete(Hashtable &h, int k) {
    List p = SearchList(h, k);
    if (p.head == NULL) {
        return 0;
    } else {
        Node* find = Search(h, k);
        if (find->next == NULL) {
            Del_Tail(p);
            return 1;
        } else if (p.head == find) {
            Del_Head(p);
            return 1;
        } else {
            Del_SpecialPos(p, k);
            return 1;
        }
    }
    return 0;
}
int main()
{
    Hashtable hashtable;

    int m, n, k;
    Hocsinh hs;

    cin >> m;
    CreateHashtable(hashtable, m);
    for (int i = 0; i < m; i++) {
        cin >> k;
        hashtable.n += k;
        for (int j = 0; j < k; j++) {
            Input(hs);
            AddTail(hashtable.table[i], hs);
        }
    }
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> k;

        if (Delete(hashtable, k) == 0)
            cout << "KHONG XOA DUOC\n";
    }
    PrintHashtable(hashtable);
    DeleteHashtable(hashtable);
    return 0;
}
