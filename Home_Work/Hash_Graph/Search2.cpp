/*###Begin banned keyword - each of the following line if appear in code will raise error. regex supported
define
include
###End banned keyword*/
#include <iostream>
#include <string>

#define LOAD 0.7
#define EMPTY 0
#define DELETE -1
using namespace std;

struct Hocsinh {
    int Maso;
    string Hoten;
    int Namsinh;
    bool Gioitinh;
    double TBK;
};

struct Hashtable {
    int M; // Kich thuoc bang bam
    int n; // so phan tu trong bang bam
    Hocsinh *table;
};
void Input(Hocsinh &x) {
    cin >> x.Maso;
    getline(cin>>ws, x.Hoten);
    cin >> x.Gioitinh;
    cin >> x.Namsinh;
    cin >> x.TBK;
}

//###INSERT CODE HERE -
void CreateHashtable(Hashtable &h,int m){
    h.M = m;
    h.n = 0;
    h.table = new Hocsinh[m];
    for(int i =0; i < m;i ++){
        h.table[i].Maso = 0;
        h.table[i].Gioitinh = false;
        h.table[i].Hoten = "";
        h.table[i].Namsinh = 0;
        h.table[i].TBK =0.0;
    }
}
int Search(Hashtable h,int k,int nprob){
    int idx;
    for(int i = 0;i < h.M;i ++){
        idx =((k % h.M) + i*i) % h.M;
        if(h.table[idx].Maso == k){
            return nprob = idx;
        }
        else{
            for(int j = i + 1; j < h.M;j ++){
                idx = ((k % h.M) + j*j) % h.M;
                if(h.table[idx].Maso == k){
                    return nprob = idx;
                }
            }
        }
    }
    return -1;
}
void DeleteHashtable(Hashtable &h){
    for(int i =0 ;i < h.M;i ++){
        h.table[i].Maso = 0;
        h.table[i].Gioitinh = false;
        h.table[i].Hoten = "";
        h.table[i].Namsinh = 0;
        h.table[i].TBK = 0.0;
    }
}
int main()
{
    Hashtable hashtable;

    int m, n, k, nprob;
    Hocsinh hs;

    cin >> m;
    CreateHashtable(hashtable, m);
    for (int i = 0; i < m; i++) {
        Input(hs);
        hashtable.table[i] = hs;
        if (hs.Maso > 0)
            hashtable.n++;
    }
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> k;
        if (Search(hashtable, k, nprob) >- 1) {
            cout << "THAM DO " << nprob << endl;
        }
        else {
            cout << "KHONG TIM THAY" << endl;
        }
    }
    DeleteHashtable(hashtable);
    return 0;
}
