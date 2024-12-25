/*###Begin banned keyword - each of the following line if appear in code will raise error. regex supported
define
include
using
###End banned keyword*/

#include <iostream>
using namespace std;

//###INSERT CODE HERE -
int check = 0;
struct node{
    int info;
    node*left, *right;
};
typedef node* Tree;
Tree getNode(int x)
{
    Tree temp = new node;
    temp->info = x;
    temp->left = temp->right = nullptr;
    return temp;
}
void insertTree(Tree &T, int x){
    if(T){
        if(T->info == x) return;
        else if(x < T->info){
            
            insertTree(T->left,x);
        }
        else {
            insertTree(T->right,x);
        }
    }
    else 
    {
        T = getNode(x);
    }
}
void LNR(Tree T)
{
    if(!T){
        return ;
    }
    LNR(T->left);
    cout<<T->info<<" ";
    LNR(T->right);
}

void inputTree(Tree &T){
    int n;cin>>n;
    for(int i = 0 ;i < n;i ++){
        int temp;
        cin>>temp;
        insertTree(T,temp);
    }
}
void NLR(Tree T){
    if(!T){
        return ;
    }
    cout<<T->info<<" ";
    NLR(T->left);
    NLR(T->right);
}
void replace(Tree &p,Tree &k){
    if(k->left){
        replace(p,k->left);
    }
    else{
        p->info = k->info;
        p = k;
    }
}
void deleting(Tree &T, int m){
    if(!T){
        return;
    }
    if(m < T->info){
        deleting(T->left,m);
    }
    else if(m > T->info){
        deleting(T->right,m);
    }
    else{
        if(!T->right && !T->left && T){
            T = NULL;
            return;
        }
        else if(T->left && !T->right){
            Tree temp = T;
            T = T->left;
            delete temp;
        }
        else if(!T->left && T->right){
            Tree temp = T;
            T = T->right;
            delete temp;
        } 
        else{
            Tree p = T;
            Tree k = T->right;
            while(k->left){
                p = k;
                k = k->left;
            }
            T->info = k->info;
            if(p != T){
                p->left = k->right;
            }
            else{
                p->right = k->right;
            }
            delete k;
        }
    }
}
void deleteRoot(Tree &T,int m){
    for(int i = 0;i < m;i ++){
        if(T){
            deleting(T,T->info);
        }
        
    }
}
int isCompleteBinaryTree(Tree T){\
    if(!T){
        return 0;
    }
    if(T->right->info > T->info){
        check = 1;
    }
    else if(T->left->info < T->info){
        check = 1;
    }
    if(!check){
        return 0;
    }
    check = isCompleteBinaryTree(T->left);
    check = isCompleteBinaryTree(T->right);
    return check;

}
int main()
{
	Tree T = NULL;
	inputTree(T);
	cout<<"LNR: "; LNR(T);
	int i=isCompleteBinaryTree (T);
	if(i==0) cout<<"\nThe tree is not a Complete Binary Tree";
    else cout<<"\nThe tree is a Complete Binary Tree";
	return 0;
}


