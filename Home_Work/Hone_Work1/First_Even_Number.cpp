/*###Begin banned keyword - each of the following line if appear in code will raise error. regex supported
define
include
###End banned keyword*/


#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void nhapMang(vector<int> &a, int &n)
{



//###INSERT CODE HERE -
    cin>>n;
    for(int i =0 ;i < n ;i ++){
        int temp ;
        cin>>temp;
        a.push_back(temp);
    }
}
void xuatMang(vector<int> a, int n){
    cout<<"Mang vua nhap:"<<endl;
    for(int i = 0 ;i < n;i++){
        cout<<a[i]<< " ";
    }
    cout<<endl;
}
void xuatsochan_dautien(vector<int> a, int n){
    for(int i  =0 ;i < n ;i ++){
        if(a[i]%2 == 0){
            cout<<a[i]<<" la so chan dau tien, co chi so "<<i<<" trong mang"<<endl;
            return;
        }
    }
}
void xuatsochan_cuoi(vector<int> a, int n){
    for(int i  = n - 1 ;i > 0 ;i --){
        if(a[i]%2 == 0){
            cout<<a[i]<<" la so chan cuoi cung, co chi so "<<i<<" trong mang"<<endl;
            return;
        }
    }
}
void Max_Even(vector<int> a, int n){
    int max = 0;
    for(int i = 0 ;i < n;i ++){
        if(a[i] % 2 == 0){
            max = a[i];
            break;
        }
    }
    for(int i = 0 ;i < n ; i++){
        if(max < a[i] && a[i]%2 == 0){
            max = a[i];
        }
    }
    cout<<"So chan lon nhat: "<<max<<endl;
}
bool EvenVec(vector<int> a, int n){
    int cnt = 0;
    for(int i = 0 ;i < n; i++){
        if(a[i]%2==0){
            cnt++;
            continue;
        }
    }
    if(cnt == 0){
        return false;
    }
    return true;
}
int main(){
    vector<int> a;
    int n;
    nhapMang(a,n);
    xuatMang(a,n);
    if(EvenVec(a,n) == true){
        xuatsochan_dautien(a,n);
        xuatsochan_cuoi(a,n);
        Max_Even(a,n);
    }
    else {
        cout<<"Mang khong co so chan"<<endl;
    }
    return 0;
    
}
