#include<bits/stdc++.h>
using namespace std;
void outputVec(vector<int> list){
    for(int i = 0 ;i < list.size(); i++){
        cout<<list[i]<<endl;
    }
}
void Delete(vector<int> &list){
    int max = list[0];
    for(int i = 0 ;i < list.size();i++){
        if( max < list[i]){
            max = list[i];
        }
    }
    list.erase(remove(list.begin(),list.end(),max),list.end());              

}
int main(){
    vector<int> list;
    while(1){
        int n; cin>>n;
        if(n == -2){
            sort(list.begin(),list.end(),greater<int>());
            cout<<list.size()<<endl;
            outputVec(list);
            break;
        }
        else if(n == -1){
            Delete(list);
        }
        else{
            int tmp = n;
            list.push_back(tmp);
        }
    }
    return 0;
}