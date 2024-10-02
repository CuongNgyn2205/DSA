#include<iostream>
#include<stack>
#include<queue>
using namespace std;
int isValid(string &expr){
    stack<char> st;
    for(int i = 0; i < expr.length();i++){
		if(expr[i] == '(' || expr[i] == '{'){
            st.push(expr[i]);
        }
        else if(expr[i] == ')' || expr[i] == '}'){
            if(st.empty()) return 0;
            if((st.top() == '(' && expr[i] == ')')|| (st.top() =='{' && expr[i] =='}')){
                st.pop();
            }
            else return 0;
        }
	}
    return st.empty();
}
int main(){
    string expr; cin>>expr;
	cout<< isValid(expr);

	return 0;
}