/*###Begin banned keyword - each of the following line if appear in code will raise error. regex supported
define
include
using
###End banned keyword*/

#include<string>
#include<cstring>
#include <iostream>

#define MAX 2000
#define NULLDATA -1

using namespace std;


//###INSERT CODE HERE -
struct Stack{
	char arr[MAX];
	int n;
};
void Init(Stack&S){
	S.n = 0;
}
bool isEmpty(Stack S){
    return S.n == 0;
}
bool isFull(Stack S){
    return S.n == MAX;
}
void Push(Stack &S, char x){
    if(!isFull(S)){
        S.arr[S.n] = x;
        S.n++;
    }
}
void Pop(Stack &S){
	if(!isEmpty(S)){
        S.n--;
    }
}
char top (Stack S){
    if(!isEmpty(S)){
        return S.arr[S.n-1];
    }
    return '\0';
}
int isValid(string &expr){
	Stack S;
	Init(S);
	for(int i = 0; i < expr.length();i++){
		if(expr[i] == '(' || expr[i] == '{'){
            Push(S,expr[i]);
        }
        else if(expr[i] == ')' || expr[i] == '}'){
            if(isEmpty(S)) return 0;
            if((top(S) == '(' && expr[i] == ')')|| (top(S) =='{' && expr[i] =='}')){
                Pop(S);
            }
            else return 0;
        }
	}
    return isEmpty(S);

}
int main()
{
	string expr; cin>>expr;
	cout<< isValid(expr);

	return 0;
}



