#include<bits/stdc++.h>
using namespace std;
struct Node{
    int info;
    Node *pLeft,*pRight;
};
typedef Node* Tree;
Node* GetNode(int x){
    Node* temp = new Node;
    temp->info = x;
    temp->pLeft = temp->pRight = NULL;
    return temp;
}
void insertNode(Tree &T, int x){
    if(!T){
        Tree p = GetNode(x);
        T = p;
    }
    else if(T->info > x){
        insertNode(T->pLeft,x);
    }
    else{
        insertNode(T->pRight,x);
    }
}
void insertTree(Tree &T, int &n){
    cin>>n;
    int temp;
    for(int i =0 ;i < n;i ++){
        cin>>temp;
        insertNode(T,temp);
    }
}
int Path(Tree T,int x,vector<int> &path){
    if(!T){
        return false;
    }
    path.push_back(T->info);
    if(T->info == x){
        return true;
    }
    if(Path(T->pLeft,x,path)||Path(T->pRight,x,path)){
        return true;
    }
    path.pop_back();
    return false;
}
void Print(Tree T,int x){
    vector<int> path;
    if(Path(T,x,path)){
        cout<<"Found. Path: ";
        for(int i = 0 ;i < path.size();i++){
            cout<<path[i]<<" ";
        }
    }
    else{
        cout<<"Not found";
    }
}
int main(){
    Tree T;
    T = NULL;
    int n;
    insertTree(T,n);
    int x;
    cin>>x;
    Print(T,x);
    system("pause");
}