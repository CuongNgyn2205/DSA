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
void LNR(Tree T){
    if(T){
        LNR(T->left);
        cout<<T->val<<" "; 
        LNR(T->right);  
    }
}
int isFullBinaryTree(Tree T){
    if(!T){return 1;}
    if(T){
        if(T->left != NULL && T->right == NULL){
            return 0;
        }
        else if(T->left == NULL && T->right != NULL){
            return 0;
        }
    }
    return isFullBinaryTree(T->left) && isFullBinaryTree(T->right);
}
int main()
{
	Tree T = NULL;
	inputTree(T);
	cout<<"LNR: "; LNR(T);
	int i=isFullBinaryTree (T);
	if(i==0) cout<<"\nThe tree is not a Full Binary Tree";
    else cout<<"\nThe tree is a Full Binary Tree";
	return 0;
}

