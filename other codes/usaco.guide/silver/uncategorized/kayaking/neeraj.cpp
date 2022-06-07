#include <bits/stdc++.h>
using namespace std;

int main()
{
int n;
vector<int> w;
vector<int> l;
cin>>n;
for(int i=0;i<(2*n);i++){
int a;
cin>>a;
w.push_back(a);
}
sort(w.begin(),w.end());
l=w;
//for(int i:l)cout<<i<<" ";cout<<endl;
int temp=0;int ans=50000000;
for(int i=0;i<2*n-1;i++){
    for(int j=i+1;j<2*n;j++){
        l.erase(l.begin()+i);l.erase(l.begin()+j-1);
        for(int k=1;k<l.size();k+=2){
            temp=temp+(l[k]-l[k-1]);
        }ans=min(ans,temp);//if(i==4)for(int i:l)cout<<i<<" "<<endl;
        l=w;
        temp=0;
    }
}
cout<<ans<<endl;
return 0;
}
