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
int nodesWithLevel(Tree T, int k, int c);

int main()
{
    Tree T = NULL;
    inputTree(T);
    cout<<"\nNLR: "; NLR(T);
    int k; cout<<"\nEnter k: "; cin >>k;
    cout<<nodesWithLevel(T,k,0); //neu tham so thu 3 khong can dung thi trong ham khong can xu ly

    return 0;
}
//###INSERT CODE HERE -
Node* Getnode(int x){
    Node* temp = new Node;
    temp->info = x;
    temp->pLeft = temp->pRight = NULL;
    return temp;
}
void insertNode(Tree &T, int t){
    if(!T){
        T = Getnode(t);
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
void printnode(Tree T,int l,int k,int &c){
    if(!T){
        return;
    }
    if(l == k){
        cout<<T->info<<" ";
        c++;
        return;
    }
    printnode(T->pRight,l+1,k,c);
    printnode(T->pLeft,l+1,k,c);
}
int nodesWithLevel(Tree T, int k, int c){
    cout << "List of nodes with level "<<k<<" (R->L): ";
    printnode(T,0,k,c);
    cout << "\nNumber of nodes with level "<<k<< ": ";
    return c;
}