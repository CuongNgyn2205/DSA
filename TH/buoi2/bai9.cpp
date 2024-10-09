#include<bits/stdc++.h>
#include<stack>
#include<queue>
using namespace std;
int kq(string &formula){
    stack<int> nums;
    queue<char> sign;
    for(int i =0 ;i < formula.length();i++){
        if(formula[i] == '+' || formula[i] == '-' ||formula[i] == '*' || formula[i]==':'){
            sign.push(formula[i]);
        }
        else {
            nums.push(formula[i]);
        }
        if(formula[i] == '('){
            sign.push(formula[i]);
            if(formula[i] != ')'){
                nums.push(formula[i]);
            }
            else if(formula[i] ==')'){
                sign.push(formula[i]);break;
            }
            else {
                sign.push(formula[i]);
            }
        } 
        
    }
}
int main(){
    string formula;
    cout<< kq(formula);
    return 0;
}