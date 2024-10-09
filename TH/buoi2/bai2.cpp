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
    int t; // t là chỉ số của phần tử cuối mảng, tức là đỉnh stack
};
void Init(Stack &S)
{
    S.t=-1; //Khi stack chưa có phần tử nào thì top được khởi tạo là -1,
            // nếu khởi tạo t = 0 là SAI vì khi đó sẽ hiểu top tại a[0]
}
//###INSERT CODE HERE -
bool isFull(Stack S){
    return S.t == MAX;
}
bool isEmpty(Stack S){
    return S.t == -1;

}
void Push(Stack &S, int &x){
    if(isFull(S) != true){
        S.arr[++S.t] = x;
    }
}
void printStack(Stack S){
    if(isEmpty(S) == true){
        cout<<"Stack is empty";
    }
    else{
        for(int i =0 ;i < S.t + 1;i ++){
            cout<<S.arr[i]<<" ";
        }
    }
}
int Top(Stack S){
    if(isEmpty(S) == true){
        return -1;
    }
    else{
        return S.arr[S.t];
    }
}
void Pop(Stack &S){
    if(isEmpty(S) == false){
        S.t--;
    }
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



