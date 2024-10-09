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
    Node*left, *right;
};
typedef Node* Tree;
Node* GetNode(int x)
{
    Node* temp = new Node;
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
Node* Search(Tree T, int x){
    Node* temp = T;
    while(temp){
        if(temp->info == x){
            return temp;
        }
        else if( x > temp->info){
            temp = temp->right;
        }
        else {
            temp = temp->left;
        }
    }
    return nullptr;
}
int minValue(Tree T){
    Node * min = T;
    while(min && min->left){
        min=min->left;
    }
    return min->info;
}
int maxValue(Tree T){
    Node * max = T;
    while(max && max->right){
        max = max->right;
    }
    return max->info;
}
void listLeafs(Tree T){
    if(!T){return;}
    Node* pos = T;
    if(T->left == nullptr && T->right == nullptr){
        cout<<T->info<<" ";
    }
    listLeafs(T->left);
    listLeafs(T->right);
}
void listInternalNodes(Tree T,int x){

    if(!T){return;}
    if((T->left != nullptr && T->right ==nullptr) || (T->left == nullptr && T->right !=nullptr) && x!= 0){
        cout<<T->info<<" ";
    }
    listInternalNodes(T->right,x);
    listInternalNodes(T->right,x);
}
void listNodesWithTwoChildren(Tree T){
    if(!T){return;}
    if(T->left != nullptr && T->right !=nullptr){
        cout<<T->info<< " ";
    }
    listNodesWithTwoChildren(T->left);listNodesWithTwoChildren(T->right);
}
void listNodesWithOneChild(Tree T){
    if(!T){return;}
    if((T->left != nullptr && T->right ==nullptr) || (T->left == nullptr && T->right !=nullptr)){
        cout<<T->info<<" ";
    }
    listNodesWithOneChild(T->left);listNodesWithOneChild(T->right);
}
int main()
{
	Tree T = NULL;
	inputTree(T);
	cout<<"\nNLR: "; NLR(T);
	cout<<"\nLRN: "; LRN(T);
	cout<<"\nLNR: "; LNR(T);

	cout<<"\nLeaf nodes: "; listLeafs(T);
	cout<<"\nInternal nodes: "; listInternalNodes(T,0); //co de san tham so thu 2 cho ai co nhu cau dung, SV khong dung tham so thu 2 nay cung khong sao
	cout<<"\nNodes with one child: "; listNodesWithOneChild(T);
	cout<<"\nNodes with two children: "; listNodesWithTwoChildren(T);

	return 0;
}
