#include<bits/stdc++.h>
using namespace std;
void inputArray(int *a, int n){
    for(int i =0 ;i < n ;i ++){
        a[i] = -10000 + (rand() % 10000);
    }
}
void outputArray(int *a,int n){
    for(int i = 0;i < n; i ++){
        cout<<a[i]<<" ";
    }
    cout<<endl;
}
void InsertionSort(int *a, int n){
    for(int i = 1 ;i < n ;i ++){
        int key = a[i];
        int j = i - 1;
        for(j; j >= 0 && a[j] > key; j --){
            a[j+1] = a[j];
            outputArray(a,n); cout<<endl;
        }
        a[j+1] = key;
        outputArray(a,n);cout<<endl;
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
void QuickSort(int *a, int l, int r){
    int mid = (l + r)/ 2;
    int pivot = a[mid];
    int i = l, j = r;
    if(l >= r){
        return;
    }
    while(i<=j){
        while(a[i] < pivot){
            i++;
        }
        while(a[j] > pivot){
            j--;
        }
        if(i <= j){
            swap(a[i],a[j]);
            i++;j--;
        }
    }
    if(l < j){
        QuickSort(a,l,j);
    }
    if(r > i){
        QuickSort(a,i,r);
    }
}

void SelectionSort(int *a, int n){
    for(int i = 0 ; i < n - 1; i ++){
        int min = i;
        for(int j = i + 1 ; j < n ; j++){
            if(a[min] > a[j]){
                min = j;
            }
        }
            swap(a[min],a[i]);
    }
}
void InterchangeSort(int *a, int n){
    for(int i = 0 ; i < n - 1; i ++){
        int min = i;
        for(int j = i + 1 ; j < n ; j++){
            if(a[min] > a[j]){
                min = j;
            }
        }
            swap(a[min],a[i]);
    }
}
//Binary Insertion sort được lấy từ nguồn geeksforgeeks.org
int BinarySearch(int *a, int key, int l,int r){
    if(l <= r){
        return (key > a[l]) ? (l + 1): l;
    }
    int mid = l + (r - l)/2;
    if(key == a[mid]){
        return mid + 1;
    }
    else if(key > a[mid]){
        return BinarySearch(a,key,mid+1,r);
    }
    return BinarySearch(a,key,l,mid - 1);
}
void BinaryInsertionSort(int *a, int n){
     int i, loc, j, k, selected;
 
    for (i = 1; i < n; ++i)
    {
        j = i - 1;
        selected = a[i];
        loc = BinarySearch(a, selected, 0, j);
        while (j >= loc)
        {
            a[j + 1] = a[j];
            j--;
        }
        a[j + 1] = selected;
    }
}
void BubbleSort(int *a ,int n){
    for(int i = 0;i < n - 1; i ++){
        for(int j = 0 ;j < n - 1 ;j ++){
            if(a[j] > a[j + 1]){
                swap(a[j],a[j + 1]);
            }
        }
    }
}
//shakesort được lấy ý tưởng từ github: https://github.com/AlexRogalskiy/Sorting-algorithms/blob/f40d0f7f1d1c1ea0f45b7098d2eac25504933eb9/src/sort/ShakeSort.java#L3
//được điều chỉnh nhờ chatgpt
void ShakeSort(int *a ,int n){
    bool swapped = true;
    int start = 0;
    int end = n - 1;
    while (swapped) {
        swapped = false;
        for (int i = start; i < end; i++) {
            if (a[i] > a[i + 1]) {
                swap(a[i], a[i + 1]);
                swapped = true;
            }
        }
        if (!swapped) break;
        end--;
        for (int i = end - 1; i >= start; i--) {
            if (a[i] > a[i + 1]) {
                swap(a[i], a[i + 1]);
                swapped = true;
            }
        }
        start++;
    }
}
// nguồn lấy từ geeksforgeeks.org
void heapify(int*a, int n, int i){
    int largest = i;
    int l = 2 * i + 1;
    int r = 2 * i + 2;
    if (l < n && a[l] > a[largest])
        largest = l;

    if (r < n && a[r] > a[largest])
        largest = r;
    if (largest != i) {
        swap(a[i], a[largest]);
        heapify(a, n, largest);
    }
}
void HeapSort(int *a,int n){
    for (int i = n / 2 - 1; i >= 0; i--)
        heapify(a, n, i);
    for (int i = n - 1; i > 0; i--) {
        swap(a[0], a[i]);
        heapify(a, i, 0);
    }
}
// nguồn lấy từ geeksforgeeks.org
void CountingSort(int *a ,int n){
    int M = 0;
    for(int i =0 ;i < n;i ++){
        M = max(M,a[i]);
    }
    vector<int> count(M + 1,0);
    for(int i =0 ;i < n;i ++){
        count[a[i]]++;
    }
    for(int i = 1; i <= M; i++) {
        count[i] += count[i - 1];
    }
    vector<int> output(n);
    for(int i = n - 1;i >= 0;i--){
        output[count[a[i]] - 1] = a[i];
        count[a[i]]--;
    }
    for(int i =0 ;i < n;i++){
        a[i] = output[i];
    }
}
//Shell Sort được lấy từ geeksforgeeks
void ShellSort(int *arr, int n)
{
    for (int gap = n/2; gap > 0; gap /= 2)
    {
        for (int i = gap; i < n; i += 1)
        {
            int temp = arr[i];
            int j;            
            for (j = i; j >= gap && arr[j - gap] > temp; j -= gap)
                arr[j] = arr[j - gap];
            arr[j] = temp;
        }
    }
}
int getMax(int *a, int n)
{
    int mx = a[0];
    for (int i = 1; i < n; i++)
        if (a[i] > mx)
            mx = a[i];
    return mx;
}
//Radix sort được lấy từ geeksforgeeks
void countSort(int *a, int n, int exp)
{
    int output[n];
    int i, count[10] = { 0 };
    for (i = 0; i < n; i++)
        count[(a[i] / exp) % 10]++;
    for (i = 1; i < 10; i++)
        count[i] += count[i - 1];

    for (i = n - 1; i >= 0; i--) {
        output[count[(a[i] / exp) % 10] - 1] = a[i];
        count[(a[i] / exp) % 10]--;
    }
    for (i = 0; i < n; i++)
        a[i] = output[i];
}
void RadixSort(int *a, int n)
{
    int m = getMax(a, n);
    for (int exp = 1; m / exp > 0; exp *= 10)
        countSort(a, n, exp);
}
int main(){
    char k;int n;
    do{
        
        do{
            cout<<"Please enter a number in range 1 .. 100,000,000:";cin>>n;
        }
        while(n < 0);
        int *a = new int [n];
        inputArray(a,n);
        cout<<"\n------------------PLEASE CHOOSE AN ALGORITHM------------------";
        cout<<"\n1.Selection Sort";
        cout<<"\n2.Interchange Sort";
        cout<<"\n3.Insertion Sort";
        cout<<"\n4.Binary Insertion Sort";
        cout<<"\n5.Bubble Sort";
        cout<<"\n6.Shake/Shaker Sort";
        cout<<"\n7.Counting Sort";
        cout<<"\n8.Quick Sort";
        cout<<"\n9.Merge Sort";
        cout<<"\n10.Heap Sort";
        cout<<"\n11.Shell Sort";
        cout<<"\n12.Radix Sort";
        int choice;
        cin>>choice;
        switch(choice){
            case 1:{
                SelectionSort(a,n);
                break;
            }
            case 2:{
                InterchangeSort(a,n);
                break;
            }
            case 3:{
                InsertionSort(a,n);
                break;
            }
            case 4:{
                BinaryInsertionSort(a,n);
                break;
            }
            case 5:{
                BubbleSort(a,n);
                break;
            }
            case 6:{
                ShakeSort(a,n);
                break;
            }
            case 7:{
                CountingSort(a,n);
                break;
            }
            case 8:{
                QuickSort(a,0,n-1);
                break;
            }
            case 9:{
                MergeSort(a,0,n-1);
                break;
            }
            case 10:{
                HeapSort(a,n);
                break;
            }
            case 11:{
                ShellSort(a,n);
                break;
            }
            case 12:{
                RadixSort(a,n);
                break;
            }
            default:{
                break;
            } 
        }
        outputArray(a,n);
        delete[] a;
        cout<<"Do you want to continue(y/n):";cin>>k;
        if(k != 'y'){
            cout<<"See you again\n";
        }
    }
    while(k =='y');
    return 0;
}