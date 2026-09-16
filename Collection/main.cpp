#include <bits/stdc++.h>
using namespace std;
#include "list"
int main(){
    int n;
    cin>>n;
    List<int> *pL = new ArrList<int>;
    ((ArrList<int>*)pL)->resize(n);
    for(int i=0; i<n; ++i){
        pL->insert(rand()%100, i);
    }
    pL->traserve([](int &val){cout<<setw(5)<<val<<", ";}); cout<<"\n";
}