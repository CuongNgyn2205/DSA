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
        if(t < -200 and t > 200){return ;}
        if(checking(T,t)){
            return;
        }
        else{
            Tree p = Getnode(t);
            inputNode(T,p);
        }
    }
}
int findx(Tree T, int x, int re) {
    while (T) {
        if (T->val < x) { 
            re = T->val;
            T = T->right;
        } else {
            T = T->left;
        }
    }
    return re;
}
bool exist(Tree T,int x){
    while(T){
        if(T->val == x){
            return true;
        }
        else if(T->val > x){
            T = T->left;
        }
        else T= T->right;
    }
    return false;
}
void printTree(Tree T){
    if(!T){
        return;
    }
    cout<<T->val<<" ";
    printTree(T->left);
    printTree(T->right);
    
}
void floorx(Tree T,int x){
    int base = x;
    int ans = findx(T, base,-201);
    if (ans == -201) {
        if(exist(T,x) == true){
            cout<<base<<endl;
            return;
        }else{
            cout<<ans<<endl;
            return;
        }
    } 
    else {
        cout<<ans<<endl;
        return;
    }
}
int main()
{
	Tree T = NULL;
	inputTree(T);
    int x; cin>>x;
    floorx(T,x);
    return 0;
}
