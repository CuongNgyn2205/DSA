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
typedef struct Node *Tree;
Node *getNode(int x);
void insertNode(Tree &T, int x);
void inputTree(Tree &T);
void NLR(Tree T);
int nodesWithLevel(Tree T, int k, int c);

int main()
{
    Tree T = NULL;
    inputTree(T);
    cout << "\nNLR: ";
    NLR(T);
    int k;
    cout << "\nEnter k: ";
    cin >> k;
    cout << nodesWithLevel(T, k, 0); // neu tham so thu 3 khong can dung thi trong ham khong can xu ly

    return 0;
}
// ###INSERT CODE HERE -
Node * getNode(int x){
    Node* temp = new Node;
    temp->info = x;
    temp->pRight = temp->pLeft = NULL;
    return temp;
}
void insertNode(Tree &T,int x){
    if(!T){
        Node *p = getNode(x);
        T = p;
    }else if(T->info > x){
        insertNode(T->pLeft, x);
    }else{
        insertNode(T->pRight, x);
    }
}
void inputTree(Tree &T){
    int n, t;cin>>n;
    for(int i = 0;i < n;i ++){
        cin>>t;
        insertNode(T,t);
    }
}
void NLR(Tree T){
    if(!T){
        return;
    }
    cout<<T->info<<" ";
    NLR(T->pLeft);
    NLR(T->pRight);
}
int nodesWithLevel(Tree T, int k, int c){
    if(T == NULL){
        return 0;
    }
    else if(k == 0){
        cout<<T->info<<" ";
        return 1;
    }
    else{
        c = nodesWithLevel(T->pRight,k - 1,c);
        c = nodesWithLevel(T->pLeft, k - 1,c);
    }
    return c;
}
