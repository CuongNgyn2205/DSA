/*###Begin banned keyword - each of the following line if appear in code will raise error. regex supported
define
include
using
###End banned keyword*/

#include <iostream>
#include <cstring>
#include <string>
using namespace std;

//###INSERT CODE HERE -
typedef struct PROVINCE
{
    int id;
    string name;
    int pop;
    float area;
}pro;
struct node
{
    pro info;
    node* next;
};
struct List
{
    node *head, *tail;
};
void inputProvince(pro &x) 
{
    cin>>x.id;
    cin.ignore();
    getline(cin,x.name);
    cin>>x.pop>>x.area;
    cin.ignore();
}
void outputProvince(pro x) //xuất thông tin của 1 tỉnh thành phố
{
    cout<<x.id<<" "<<x.name<<" "<<x.pop<<" "<<x.area;
}
node* GetPro(pro x){
    node*p = new node;
    p->next = NULL;
    p->info = x;
    return p;
}
void addTail (List &L, pro x){
    node* p = GetPro(x);
    if(L.head == NULL){
        L.head = L.tail = p;
    }
    else {
        L.tail->next = p;
        L.tail = p;
    }
}  //đề yêu cầu thêm cuối
void inputListProvinces (List &L)
{
    int n; cin>>n; //số lượng tỉnh-thành
    pro x;
    for(int i = 0 ; i < n;i ++)
    {
        inputProvince(x);
        addTail(L,x);
    }
}
void Init(List &L){
    L.head = L.tail = NULL;
}
void outputListProvinces(List L){
    node*p = L.head;
    while(p != NULL){
        outputProvince(p->info);
        cout<<endl;
        p=p->next;
    }
}
void outputProvincesMore1MillionPop(List L){
    node*p = L.head;
    while(p){
        if(p->info.pop > 999){
            outputProvince(p->info);cout<<endl;
        }
        p = p->next;
    }
}
node* findProMaxArea(List L){
    node*p = L.head;
    node* max = L.head;
    while(p){
        if(p->info.area > max->info.area){
            max = p;
        }
        p=p->next;
    }
    return max;
}
int main()
{
    List L;
    Init(L);
    inputListProvinces(L);
    cout<<"List of provinces:"<<endl;
    cout<<"ID\t|Province\t|Population\t|Area"<<endl;
    outputListProvinces(L);

    cout<<"Provinces with a population of more than 1 million:"<<endl;
    outputProvincesMore1MillionPop(L);

    cout<<"The largest province:"<<endl;
    node *p = findProMaxArea(L);
    if(p) outputProvince(p->info);

    return 0;
}



