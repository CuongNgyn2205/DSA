/*###Begin banned keyword - each of the following line if appear in code will raise error. regex supported
define
include
using
###End banned keyword*/

#include <iostream>
using namespace std;


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
int depthOfTree(Tree T){
    if(!T){
        return -1;
    }
    return max(depthOfTree(T->left),depthOfTree(T->right)) + 1;
}
void countEven(Tree T, int &cE){
    if(!T){
        return;
    }
    if(T->info %  2 == 0){
        cE++;
    }
    countEven(T->left,cE);
    countEven(T->right,cE);
}
void countOdd(Tree T, int &cO){
    if(!T){
        return;
    }
    if(T->info % 2 != 0){
        cO++;
    }
    countOdd(T->left,cO);
    countOdd(T->right,cO);
    
}
int countPositive(Tree T){
    if(!T){
        return 0;
    }
    return countPositive(T->left) + countPositive(T->right) + (T->info>0?1:0);
}
int countNegative(Tree T){
    if(!T){
        return 0;
    }
    
    return countNegative(T->left) + countNegative(T->right) + (T->info<0?1:0);
}
int isPrime(int x){
    if(x<=1){
        return 0;
    }
    if(x==2){
        return 1;
    }
    for(int i = 2 ; i*i<=x;i++){
        if(x%i == 0){
            return 0;
        }
    }
    return 1;
}
int countPrime(Tree T){
    if(!T){
        return 0;
    }
    return isPrime(T->info) + countPrime(T->left) + countPrime(T->right);
}
void listPrime(Tree T){
    if(!T){
        return;
    }
    if(isPrime(T->info) == 1){
        cout<<T->info<<" ";
    }
    listPrime(T->left);
    listPrime(T->right);
}
void RotateLeft(Tree &T){
    if(T->right == NULL){
        cout<<"Khong the xoay trai vi khong co nut con ben phai "<<endl;
        return ;
    }
    node*p = T->right;
    T->right = p->left;
    p->left = T;
    T = p;
}
void RotateRigth(Tree &T){
    if(T->left == NULL){
        cout<<"Khong the xoay trai vi khong co nut con ben trai "<<endl;
        return ;
    }
    node*p = T->right;
    T->left = p->right;
    p->right = T;
    T = p;
}
int main()
{
	Tree T = NULL;
	inputTree(T);
    cout<<"NLR: ";NLR(T);cout<<endl;
    RotateLeft(T);cout<<"NLR: ";NLR(T);cout<<endl;



	return 0;
}
