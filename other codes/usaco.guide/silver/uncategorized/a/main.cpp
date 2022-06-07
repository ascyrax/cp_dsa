#include<bits/stdc++.h>
using namespace std;
int a;
void add(int *a){
    *a=*a-3;
}
int main(){
    cin>>a;
    add(&a);
    cout<<a;
}
