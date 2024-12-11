/*###Begin banned keyword - each of the following line if appear in code will raise error. regex supported
define
include
using
###End banned keyword*/

#include <iostream>
using namespace std;

//###INSERT CODE HERE -
struct Node{
    int info;
    Node* pLeft,*pRight;
};
typedef struct Node* Tree;
Node* getNode(int x){
    Node* temp = new Node;
    temp->info = x;
    temp->pRight = temp->pLeft = NULL;
    return temp;
}
Node* Search(Tree T,int b){
    while(T){
        if(T->info == b){
            return T;
        }
        else if(T->info > b){
            T = T->pLeft;
        }
        else{
            T = T->pRight;
        }
    }
    return NULL;
}
void SetLeft(Tree p, int c){
    if(!p){
        return;
    }
    if(p->pLeft != NULL){
        return;
    }
    else{
        p->pLeft = getNode(c);
    }
}
void SetRight(Tree p, int c){
    if(!p){
        return;
    }
    if(p->pRight != NULL){
        return;
    }
    else{
        p->pRight = getNode(c);
    }
    
}
void LNR(Tree T){
    if(T){
        LNR(T->pLeft);
        cout<<T->info<<" ";
        LNR(T->pRight);
    }
}
void DeleteLeft(Tree p){
    if(!p){
        cout<<"Node khong ton tai\n";
    }
    else{
        if(p->pLeft == NULL){
            cout << "Khong co node ben trai\n";
        }
        else if(p->pLeft->pLeft != NULL || p->pLeft->pRight != NULL){
            cout << "Khong la node la nen khong xoa duoc\n";
        }
        else{
            Node* temp = p->pLeft;
            p->pLeft = NULL;
            delete temp;
        }
    }
}
void DeleteRight(Tree p){
    if(!p){
        cout<<"Node khong ton tai\n";
    }
    else{
        if(p->pRight == NULL){
            cout << "Khong co node ben phai\n";
        }
        else{
            Node* temp = p->pRight;
            p->pRight = NULL;
            delete temp;
        }
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
        if(a!='L'&& a!='R') break;
        cin>>b>>c;
        if(a=='L') SetLeft(Search(T,b),c);
        else if (a=='R') SetRight(Search(T,b),c);

    }
	cout<<"LNR: "; LNR(T);
	cout<<"\nDelete some nodes:\n";
	string s;
	while(true)
    {
        cin>>s; // Chuoi cho biet xoa ben trai hay ben phai
        if(s!="DL"&& s!="DR") break;
        cin>>b;
        if(s=="DL") DeleteLeft(Search(T,b));
        else if(s=="DR") DeleteRight(Search(T,b));

    }
    cout<<"\nLNR: "; LNR(T);

	return 0;
}
