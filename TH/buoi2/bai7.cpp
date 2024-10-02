#include<iostream>
#include<stack>
#include<queue>
using namespace std;
void DecimaltoBinary(int x, stack<int> &S){
    while(x>0){
        S.push(x%2);
        x/=2;
    }
}
int main(){
    stack<int> S;
    int x;cin>>x;
    DecimaltoBinary(x,S);
    while(!S.empty()){
        cout<<S.top();
        S.pop();
    }
}