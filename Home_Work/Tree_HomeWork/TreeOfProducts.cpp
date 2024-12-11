/*###Begin banned keyword - each of the following line if appear in code will raise error. regex supported
define
include
using
###End banned keyword*/

#include <iostream>
#include <string>
using namespace std;

//###INSERT CODE HERE -
typedef struct Product{
    int id,year,warranty;
    string name,type;
} PRO;
struct Node{
    PRO info;
    Node *pLeft,*pRight;    
};
typedef struct Node* Tree;
Node* Getnode(PRO x){
    Tree temp = new Node;
    temp->info = x;
    temp->pLeft = temp->pRight = NULL;
    return temp;
}
void insertNode(Tree &T, PRO temp){
    if(!T){
        T = Getnode(temp);
    }
    else if (T->info.id > temp.id ){
        insertNode(T->pLeft,temp);
    }
    else {
        insertNode(T->pRight,temp);
    }
}
void inputTree(Tree &T){
    int n;
    cin>>n;
    PRO temp;
    for(int i = 0 ;i < n;i ++){
        cin>>temp.id;
        cin.ignore();
        getline(cin,temp.name);
        getline(cin,temp.type);
        cin>>temp.year>>temp.warranty;
        insertNode(T,temp);
    }
}
void listProduct(Tree T, string type){
    if(T){
        if(T->info.type == type){
            cout<<T->info.id<<" "<<T->info.name<<" "<<T->info.type<<" "<<T->info.year<<" "<<T->info.warranty<<endl;
        }
        listProduct(T->pLeft,type);
        listProduct(T->pRight,type);
    }
}
int countProduct(Tree T,int year){
    if(!T){
        return 0;
    }
    else{
        if(T->info.warranty > year){
            return 1;
        }
    }
    return countProduct(T->pLeft,year) + countProduct(T->pRight,year) ;
}
int main()
{
    Tree T = NULL;
    inputTree(T);

    string type;  cin.ignore(); getline(cin,type);
    cout<<"List of products whose type is  "<<type<<": ";
    cout<<"\nID\tName\tType\tYear\tWarranty\n";
    listProduct(T,type);

    int year;cin>>year;
    cout<<"Number of products with more than "<<year<<" years of warranty: "<<countProduct(T,year)<<endl;


	return 0;
}

