#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;cin>>n;
    vector<int>v(n);
    for(int &i:v)cin>>i;
    int sum=0;
    for(int i=0;i<n;i+=2)sum+=v[i];
    cout<<sum<<endl;
    return 0;
}
