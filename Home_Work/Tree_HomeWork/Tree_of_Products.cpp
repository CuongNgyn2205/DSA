/*###Begin banned keyword - each of the following line if appear in code will raise error. regex supported
define
include
using
###End banned keyword*/

#include <iostream>
#include <string>
using namespace std;

// ###INSERT CODE HERE -
typedef struct Product{
    int id,year,warranty;
    string name,type;
}PRO;
struct Node{
    PRO info;
    Node* pLeft, *pRight;
};
typedef Node* Tree;
Node* GetNode(PRO x){
    Node* temp = new Node;
    temp->info = x;
    temp->pLeft = temp->pRight = nullptr;
    return temp;
}
void inputNode(Tree &T,Tree x){
    if(!T){
        T = x;
    }
    else if (T->info.)
}
int main()
{
    Tree T = NULL;
    inputTree(T);

    string type;
    cin.ignore();
    getline(cin, type);
    cout << "List of products whose type is  " << type << ": ";
    cout << "\nID\tName\tType\tYear\tWarranty\n";
    listProduct(T, type);

    int year;
    cin >> year;
    cout << "Number of products with more than " << year << " years of warranty: " << countProduct(T, year) << endl;

    return 0;
}
