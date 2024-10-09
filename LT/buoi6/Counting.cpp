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
int main()
{
	Tree T = NULL;
	inputTree(T);
    cout<<"LNR: "; LNR(T); cout<<endl;
	cout<<"Number of nodes: " << countNodes(T)<<endl;
    cout<<"Depth of Tree: "<<depthOfTree(T)<<endl;

    int count_even = 0, count_odd =0;
    countEven(T, count_even);countOdd(T, count_odd);
    cout<<"Number of even nodes: "<<count_even<<endl;
    cout<<"Number of odd nodes: "<<count_odd<<endl;

    cout<<"Number of positive nodes: "<<countPositive(T)<<endl;
    cout<<"Number of negative nodes: "<<countNegative(T)<<endl;

    cout<<"Number of prime nodes: "<<countPrime(T)<<endl;
    cout<<"Prime numbers: "; listPrime(T);



	return 0;
}
