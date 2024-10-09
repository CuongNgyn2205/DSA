/*###Begin banned keyword - each of the following line if appear in code will raise error. regex supported
define
include
using
###End banned keyword*/

#include <iostream>
using namespace std;

//###INSERT CODE HERE -
void inputArray(int *a, int n){
    for(int i = 0; i< n ;i ++){
        cin>>a[i];
    }
}
void Merge(int *a ,int l, int r, int mid){
    int lsize = mid - l + 1;
    int rsize = r - mid;
    int *b = new int[lsize];
    int *c = new int [rsize];
    for(int i = 0 ;i < lsize ;i ++){
        b[i] = a[i + l];
    }
    for(int i = 0; i < rsize; i ++){
        c[i] = a[mid + 1 + i];
    }
    int i = 0, j = 0;
    int na = l;
    while(i < lsize && j < rsize){
        if(b[i] < c[j]){
            a[na++] = b[i++];
        }
        else {
            a[na++] = c[j++];
        }
    }
    while(i < lsize){
        a[na++] = b[i ++ ];
    }
    while (j < rsize)   
    {
        a[na++] = c[j ++];
    }
    delete[] b;
    delete[] c;
}
void MergeSort(int *a, int l, int r){
    if(l < r){
        int mid = l + (r - l)/2;
        MergeSort(a,l,mid);
        MergeSort(a,mid + 1,r);
        Merge(a,l,r,mid);
    }
    
}
void outputArray(int *a ,int n){
    for(int i =0 ;i < n ;i ++){
        cout<<a[i]<< " ";
    }
    cout<<endl;
}
int binarySearch(int *a,int n,int l, int r,int key){
    int i = 0, j = n - 1;
    int mid = l + (r - l)/2;
    while(l <= r){
        if(key > mid){
            l = mid + 1;
        }
        else if (key == mid)
        return mid;
        else {
            r = mid - 1;
        }
    }
    return -1;
}
int main()
{
    int n; cin>>n;
    int *a = new int[n];
    inputArray(a,n);
    MergeSort(a,0,n-1);
    cout<<"Sorted Array: ";
    outputArray(a,n);// liet ke cac phan tu cach nhau boi 1 khoang cach

    cout<< "\nFind an element: ";
    int x; cin>>x;
    cout<<x<<endl;
    int result = binarySearch(a,n,0,n-1,x);
    if (result ==-1) cout<<x<<" is not found";
    else cout<<x<<" is found at the position " << result;

	return 0;
}

