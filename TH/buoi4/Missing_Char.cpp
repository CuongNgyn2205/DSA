#include<bits/stdc++.h>
using namespace std;
void inputArr(char a[],int n){
    for(int i =0 ;i < n;i ++){
        cin>>a[i];
    }
}
void Missing(char a[],int n){
    for(int i =0 ;i < n; i++){
        a[i] = toupper(a[i]);
    }
    char*T = new char[26];
    for(int i = 0;i < 26;i++){
        T[i] = 0;
    }
    for(int i = 0;i < n;i++){
        if(a[i]>='A' &&a[i]<='Z')
        T[a[i]-'A'] = 1;
    }
    int cnt = 0;
    for(int i = 0 ;i < 26;i ++){
        if(!T[i]){
            cnt++;
        }
    }
    cout<<cnt<<endl;
}
int main(){
    int n;
    cin>>n;
    char *a = new char [n];
    inputArr(a,n);
    Missing(a,n);
    return 0;
}