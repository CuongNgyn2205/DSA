
/*###Begin banned keyword - each of the following line if appear in code will raise error. regex supported
define
include
using
###End banned keyword*/

#include <iostream>
#include <math.h>

using namespace std;

//###INSERT CODE HERE -
void inputArray(int a[],int &n){
    cin>>n;
    for(int i = 0;i < n; i ++){
        cin>>a[i];
    }
    
}
void printArray(int a[],int n){
    for(int i = 0 ;i < n;i ++){
        cout<<a[i]<< " ";
    }
    cout<<endl;
}
void removeDups(int a[],int n){
    int max = a[0];
    for(int i =0 ;i < n;i ++){
        if(max < a[i]){
            max = a[i];
        }
    }
    int *T = new int[max + 1];
    for(int i = 0;i < n;i ++){
        T[a[i]] = 1;
    }
    for(int i = 0;i <= max ;i++){
        if(T[i] == 1 ){
            cout<<i<<" ";
        }
    }
    cout<<endl;
}
int main()
{
    int a[100],n;
    inputArray(a,n);

    // In mang ban dau
    printArray(a, n);

    /* Goi ham thuc hien xuat mang nhung chi xuat nhung gia tri xuat hien lan dau tien,
    *  khong xuat nhung gia tri bi lap lai/bi trung
    */


    cout << "After removing the duplicate elements:" << endl;

    removeDups(a, n);

    return 0;
}
