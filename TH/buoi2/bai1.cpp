/*###Begin banned keyword - each of the following line if appear in code will raise error. regex supported
define
include
using
###End banned keyword*/

#include <iostream>

#define MAX 2000
#define NULLDATA -1

using namespace std;

struct Stack
{
    int arr[MAX];
    int n; // so luong phan tu cua stack
};

//###INSERT CODE HERE -
void Init(Stack &S){
    S.n = 0;
    for(int i = 0;i < MAX;i ++){
        S.arr[i] = NULLDATA;
    }
}
bool isFull(Stack S){
    return S.n == MAX;
}
bool isEmpty(Stack S){
    return S.n == 0;
}

void Push(Stack &S, int &x){
    if(isFull(S) == 0){
        S.n++;
        S.arr[S.n-1] = x;
    }
}
int Top(Stack S){
    if(isEmpty(S) == true){
        return -1;
    }
    return S.arr[S.n-1];
}
void Pop(Stack &S){
    if(isEmpty(S) == false){
        int top = S.arr[S.n-1];
        S.n--;
    }
}
void printStack(Stack S){
    if(isEmpty(S) != true){
        for(int i = 0;i < S.n;i ++){
            cout<<S.arr[i]<<" ";
        }
    }
   else cout<<"Stack is empty";
}
int main()
{
    Stack S;Init(S);
    int n,x;
    cin>>n;
    for (int i= 1; i<=n; i++)
    {
        cin>>x;
        Push(S,x);

    }
    cout<<"Stack:";
    printStack(S);
    cout<<"\nTop:"<<Top(S);
    Pop(S);
    cout<<"\nUpdated Stack:";
    printStack(S);
    cout<<"\nTop:"<<Top(S);
    return 0;
}




