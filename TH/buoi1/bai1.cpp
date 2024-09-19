/*###Begin banned keyword - each of the following line if appear in code will raise error. regex supported
define
include
###End banned keyword*/

#include <iostream>
using namespace std;

//###INSERT CODE HERE -
void QuickSort(int *b , int l, int r){
    int i = l;
	int j = r;
	int key = b[(l + r) / 2];
	while (i <= j) {
		while (b[i] < key) i++;
		while (b[j] > key) j--;
		if (i <= j) {
			swap(b[i], b[j]);
			i++;
			j--;

		}
	}
    if(l<j) QuickSort(b,l,j);
    if(r>i)QuickSort(b,i,r);

}
void sort(int *a, int n){
    int* b = new int[n];
	int* c = new int[n];
	int nb = 0, nc = 0;
	for (int i = 0; i < n; i++)
	{
		if (a[i] % 2 == 0)
		{
			b[nb++] = a[i];
			c[nc++] = i;
		}

	}
	QuickSort(b, 0, nb - 1);
	int k = 0;
	for (int i = 0; i < nc; i++)
	{
		a[c[i]] = b[k++];
	}

}
int main(){
    int *a, n; cin >> n;
    a = new int [n];
    for(int i = 0; i < n; i ++){
        cin >> a[i];
    }

    sort(a, n);

    for(int i = 0; i < n; i ++){
        cout << a[i] << " ";
    }
}
