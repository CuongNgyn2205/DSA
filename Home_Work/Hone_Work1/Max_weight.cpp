#include<bits/stdc++.h>
using namespace std;
int findmax(int*a, int n,int max1){
    int max2 = a[0];
    for(int i = 0 ;i < n;i ++){
        if(max2 < a[i] && a[i] < max1){
            max2 = a[i];
        }
    }
    return max2;
}
int findmin(int*a, int n,int min1){
    int min2 = a[0];
    for(int i = 0 ;i < n;i ++){
        if(min2 > a[i] && a[i] > min1){
            min2 = a[i];
        }
    }
    return min2;
}
int solution(int *a, int n){
    int max1,max2,min1,min2;
    for(int i = 0;i < n;i ++){
        max1 = max(max1,a[i]);
    }
    for(int i = 0;i < n;i ++){
        min1 = min(min1,a[i]);
    }
    max2 = findmax(a,n,max1);
    min2 = findmin(a,n,min1);
    return((max1 - max2) + (min2 - min1));
}
int main(){
    int T ; cin>>T;
    int cnt = 0;
    while(cnt <=T ){
        int n ; cin>>n;
        int *a = new int [n];
        for(int i = 0;i < n;i ++){
            cin>>a[i];
        }
        cout<<solution(a,n)<<endl;
    }
    return 0;
}