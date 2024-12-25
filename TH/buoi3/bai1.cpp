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
Tree Search(Tree T,int x){
    if(!T){
        return NULL;
    }
    if(T){
        if(T->info == x){
            return T;
        }
    }
    Tree le = Search(T->left,x);
    if(le){return le;}
    return Search(T->right,x);
}
void SetLeft(Tree T, int c){
    Tree temp = getNode(c);
    if(!T){
        cout<<"Node khong ton tai\n";
    }
    else if(T->left){
        cout<<"Da co node con ben trai\n";
    }
    else{
        T->left = temp;
    }
}
void SetRight(Tree T,int c){
    Tree temp = getNode(c);
    if(!T){
        cout<<"Node khong ton tai\n";
    }
    else if(T->right){
        cout<<"Da co node con ben phai\n";
    }
    else{
        T->right = temp;
    }
}

int main()
{
	Tree T = NULL;
	int x,b,c; char a;
	cin>>x;	T=getNode(x); // tao nut goc
	while(true)
    {
        cin>>a; // Ky tu cho biet chen vao trai hay phai
        if(a!='L'&& a!='R') break; // Neu khong phai L hoac R thi ket thuc viec tao cay
        cin>>b>>c;
        if(a=='L') SetLeft(Search(T,b),c); // chen c vao ben trai b
        else if (a=='R') SetRight(Search(T,b),c); // chen c vao ben phai b
    }
	cout<<"\nLNR: "; LNR(T); cout<<endl;

	return 0;
}
