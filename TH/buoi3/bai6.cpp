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
int countNodes(Tree T){
    if(!T){
        return 0;
    }
    return countNodes(T->left) + countNodes(T->right)+1;
}
int countLeafs(Tree T){
    if(!T){
        return 0;
    }
    if(!T->left && !T->right && T){
        return 1;
    }
    return 0 + countLeafs(T->left) + countLeafs(T->right);
}
int countInternalNodes(Tree T){
    if(!T){
        return 0;
    }
    if((!T->left && !T->right) || (!T->left && T->right) || (T->left && !T->right)){
        return 1;
    }
    return -1 +countInternalNodes(T->left) + countInternalNodes(T->right);
}
int countOneChild(Tree T){
    if(!T){
        return 0;
    }
    if(T->left && !T->right || !T->left && T->right){
        return 1;
    }
    else if(!T->left && T->right){
        return 1;
    }
    return countOneChild(T->left) + countOneChild(T->right);
}
int countTwoChildren(Tree T){
    if(!T){
        return 0;
    }
    else{
        if(T->left && T->right)
        return 0;
    }
    return 1 + countTwoChildren(T->left) + countTwoChildren(T->right);
}
int countLess(Tree T,int x){
    if(!T){
        return 0;
    }
    else {
        if(T->info < x){
            return 1;
        }
    }
    return countLess(T->right,x) + countLess(T->left,x);
}
int countBetweenValues(Tree T, int x,int y){
    if(!T){
        return 0;
    }
    else{
        if(T->info > x && T->info < y){
            return 1;
        }
    }
    return countBetweenValues(T->right,x,y) + countBetweenValues(T->left,x,y);
}
int main()
{
	Tree T = NULL;
	inputTree(T);

    cout<<"Number of nodes: " << countNodes(T)<<endl;
	cout<<"Number of leaf nodes: " << countLeafs(T)<<endl;
	cout<<"Number of internal nodes: "<< countInternalNodes(T)<<endl;
	cout<<"Number of nodes with one child: "<< countOneChild(T)<<endl;
	cout<<"Number of nodes with two children: "<< countTwoChildren(T)<<endl;

	int x;cout<<"Enter x: ";cin>>x;
	cout<<"\nNumber of nodes less than "<<x<<": "<< countLess(T,x)<<endl;
	int y; cout<<"Enter x,y: ";cin>>x>>y;
	cout<<"\nNumber of nodes greater than "<<x<<" and less than "<<y<<": "<< countBetweenValues(T,x,y)<<endl;

	return 0;
}
