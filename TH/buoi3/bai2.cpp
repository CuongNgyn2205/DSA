/*###Begin banned keyword - each of the following line if appear in code will raise error. regex supported
define
include
using
###End banned keyword*/

#include <iostream>
using namespace std;

//###INSERT CODE HERE -
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
int main()
{
	Tree T = NULL;
	inputTree(T);
	cout<<"NLR: "; NLR(T);
	int m; cout<<"\nEnter m: ";cin>>m;
	deleteRoot(T,m);
	cout<<"\nNLR: "; NLR(T);

	return 0;
}
