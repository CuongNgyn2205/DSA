/*###Begin banned keyword - each of the following line if appear in code will raise error. regex supported
define
include
using
###End banned keyword*/

#include <iostream>
using namespace std;

struct Node
{
    int info;
    Node *pLeft;
    Node *pRight;
};
typedef struct Node* Tree;

Node *getNode(int x);
void insertNode(Tree & T, int x);
void inputTree(Tree &T);
void NLR(Tree T);
bool isSquare (int n);
void SearchStandFor(Node* &p, Node* &q); //Chon node phai nhat tren nhanh con ben trai
void deleteSquareNumbers(Tree &T);

int main()
{
    Tree T = NULL;
    inputTree(T);
    cout<<"\nNLR: "; NLR(T);
    cout<<"\nDelete all square numbers:";
    deleteSquareNumbers(T);
    cout<<"\nNLR: "; NLR(T);

    return 0;
}
//###INSERT CODE HERE -
bool isSquare (int n){
    if(n < 0){return false;}
    int i = 1;
    while(i*i <= n){
        if(i*i == n){
            return true;
        }
        i++;
    }
    return false;
}
void SearchStandFor(Node* &p, Node* &q){
    if(q->pRight){SearchStandFor(p,q->pRight);}
    else{
        Node* temp = q;
        p->info = q->info;
        q = q->pLeft;
        delete temp;
    }
}
void deleteSquareNumbers(Tree &T){
    if(!T){return;}
    deleteSquareNumbers(T->pLeft);
    deleteSquareNumbers(T->pRight);
    if(isSquare(T->info)){
        Node* p = T;
        if(T->pLeft == NULL){
            T = T->pRight;
        }
        else if(T->pRight == NULL){
            T = T->pRight;
        }
        else{
            SearchStandFor(p,T->pLeft);
        }
        delete p;
    }
}   
Node* getNode(int x){
    Node* temp = new Node;
    temp->info = x;
    temp->pLeft = temp->pRight = NULL;
    return temp;
}
void insertNode(Tree &T, int t){
    if(!T){
        T = getNode(t);
        return;
    }
    if(T->info > t){
        insertNode(T->pLeft,t);
    }
    else if(T->info < t){
        insertNode(T->pRight,t);
    }
}
void inputTree(Tree &T){
    int n,t;
    cin>>n;
    for(int i =0 ;i < n; i++){
        cin>>t;
        insertNode(T,t);
    }
}
void NLR(Tree T){
    if(T){
        cout<<T->info<<" "; 
        NLR(T->pLeft);
        NLR(T->pRight);  
    }
    
}
