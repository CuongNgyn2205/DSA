/*###Begin banned keyword - each of the following line if appear in code will raise error. regex supported
define
include
using
###End banned keyword*/

#include <iostream>
using namespace std;

// ###INSERT CODE HERE -
struct Node{
    int val;
    Node* left,*right;
};
typedef Node* Tree;
Node* Getnode(int x){
    Node* temp = new Node;
    temp->val = x;
    temp->left = temp->right = NULL;
    return temp;
}
bool checking(Tree T,int t){
    if(T){
        if(T->val == t){
            return true;
        }
        return checking(T->left,t) || checking(T->right,t);
    }
    return false;
}
void inputNode(Tree &T, Tree p){
    if(!T){
        T = p;
    }
    if(T->val > p->val){
        inputNode(T->left,p);
    }
    else if(T->val < p->val){
        inputNode(T->right,p);
    }
}
void inputTree(Tree &T){
    int n,t;
    cin>>n;
    for(int i =0 ;i < n; i++){
        cin>>t;
        if(checking(T,t)){
            cout << "Bi trung gia tri, ket thuc qua trinh tao cay\n";
            return;
        }
        else{
            Tree p = Getnode(t);
            inputNode(T,p);
        }
    }
}
void NLR(Tree T){
    if(T){
        cout<<T->val<<" "; 
        NLR(T->left);
        NLR(T->right);  
    }
    
}
int main()
{
    Tree T = NULL;
    inputTree(T); // Khi bi trung gia tri thi ket thuc qua trinh tao cay, khong nhap tiep nua
    cout << "NLR: ";
    NLR(T);
    return 0;
}
