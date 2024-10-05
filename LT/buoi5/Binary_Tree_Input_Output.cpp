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
node* GetNode(int x)
{
    node* temp = new node;
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
        T = GetNode(x);
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
void LRN(Tree T)
{
    if(!T){
        return ;
    }
    
    LRN(T->left);
    LRN(T->right);
    cout<<T->info<<" ";
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
int main()
{
	Tree T = NULL;
	inputTree(T);
	cout<<"\nNLR: "; NLR(T);
	cout<<"\nLRN: "; LRN(T);
	cout<<"\nLNR: "; LNR(T);

	return 0;
}
