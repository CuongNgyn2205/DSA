/*###Begin banned keyword - each of the following line if appear in code will raise error. regex supported
sort
stable_sort
partial_sort
partial_sort_copy
sort_heap
set
multi_set
map
unordered_map
include
[
]
###End banned keyword*/

#include <iostream>
using namespace std;

//###INSERT CODE HERE -
struct Node{
    int info;
    Node *pLeft,*pRight;
};
typedef Node* Tree;
Node* GetNode(int x){
    Node* temp = new Node;
    temp->info = x;
    temp->pLeft = temp->pRight = NULL;
    return temp;
}
void insertNode(Tree &T, int x){
    if(!T){
        Tree p = GetNode(x);
        T = p;
    }
    else if(T->info > x){
        insertNode(T->pLeft,x);
    }
    else{
        insertNode(T->pRight,x);
    }
}
void insertTree(Tree &T){
    int n;
    cin>>n;
    while(n != -1){
        if(n == -1){
            return;
        }
        else{
            insertNode(T,n);
            cin>>n;
        }
    }
}
void Reversed_Tree(Tree T){

}
int main(){
    Tree T = NULL;
    insertTree(T);
    Reversed_Tree(T);
    return 0;
}
