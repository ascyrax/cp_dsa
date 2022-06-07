#include <bits/stdc++.h>
using namespace std;

int main()
{int n,a,b,g,ma=0;
vector<int> gu;
vector<pair <int,int>>  sh;

cin>>n;
for (int i=1;i<=n;i++){
cin>>a>>b>>g;
gu.push_back(g);
sh.push_back(make_pair(a,b));
}

for(int x=1;x<4;x++){
    int c=x;
    int p=0;
    for(int j=0; j<n;j++){
    pair<int,int> t=sh[j];
    int ta=t.first;
    int tb=t.second;
    if(c==ta)
        c=tb;
    else if (c==tb)
        c=ta;
     if(c==gu[j])
         p++;
     if(p>ma)
ma=p;
    }
    }
    cout<<ma<<endl;


}
