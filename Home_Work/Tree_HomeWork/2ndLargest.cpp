/*###Begin banned keyword - each of the following line if appear in code will raise error. regex supported
define
include
using
###End banned keyword*/

#include <iostream>
using namespace std;

//###INSERT CODE HERE -
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
int largest(Tree T, int &c) {
    if (T) {
        c = max(c, T->val);
        if (T->left) {
            c = max(c, largest(T->left, c));
        }
        if (T->right) {
            c = max(c, largest(T->right, c));
        }
    }
    return c;
}
void TheMang(Node *&p, Node *&q){
    if(q->left){TheMang(p,q->left);}
    else{
        Node* temp = q;
        p->val = q->val;
        q = q->right;
        delete temp;
    }
}
void DeleteX(Tree &T, int x){
    if(T){
        if(T->val < x) DeleteX(T->right,x);
        else{
            if(T->val > x) DeleteX(T->left,x);
            else{
                Node* p = T;
                if(T->left == NULL) T = T->right;
                else{
                    if(T->right == NULL) T = T->left;
                    else
                    TheMang(p,T->right);
                }
                delete p;
            }
        }
    }
}
void printTree(Tree T){
    if(!T){
        return;
    }
    if(T){
        cout<<T->val<<" ";
        printTree(T->left);
        printTree(T->right);
    }
}
void secondLargest(Tree T){
    if(!T){
        return;
    }
    int c = T->val;
    c = largest(T,c);
    DeleteX(T,c);
    if(!T){
        return;
    }
    c = T->val;
    c = largest(T,c);
    cout<<"2nd largest value is "<<c<<endl;
}
int main()
{
	Tree T = NULL;
	inputTree(T);
    secondLargest(T);
	return 0;
}
