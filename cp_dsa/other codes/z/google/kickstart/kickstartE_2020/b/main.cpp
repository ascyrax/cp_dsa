#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;cin>>n;
    int ta=1;
    for(int i=1;i<=n;i++){
        if(i%2==1){
            for(int j=1;j<=i;j++){
                cout<<ta++;
            }cout<<endl;
        }else{
            for(int j=1;j<=i;j++){
                cout<<"*";
            }cout<<endl;
        }
    }
    return 0;
}
