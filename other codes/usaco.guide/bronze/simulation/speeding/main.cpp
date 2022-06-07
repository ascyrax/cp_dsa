#include <bits/stdc++.h>
//#include <ext/pb_ds/assoc_container.hpp>

//using namespace __gnu_pbds;
using namespace std;

typedef  long long ll;
typedef long double ld;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

#define endl "\n"
#define ioss ios::sync_with_stdio(false);cin.tie(0);
#define pb push_back
#define eb emplace_back

double startTime;
double gct()//get_current_time
{
    return ((double)clock()-startTime)/CLOCKS_PER_SEC;
}





























void suraj(){

int n,m;cin>>n>>m;
vector<pair<int,int>>police,bessi;
for(int i=0;i<n;i++){
    int a,b;cin>>a>>b;
    police.pb(make_pair(a,b));
}
for(int i=0;i<m;i++){
    int a,b;cin>>a>>b;
    bessi.pb(make_pair(a,b));
}
for(int i=0;i<n-1;i++){
    police[i+1].first+=police[i].first;
}
for(int i=0;i<m-1;i++){
    bessi[i+1].first+=bessi[i].first;
}
//
vector<int>p(101),b(101);
int temp=0;
for(int i=0;i<n;i++){
    int a=police[i].first;
    for(int j=temp;j<=a;j++){
        p[j]=police[i].second;
    }
    temp=police[i].first+1;
}
temp=0;
for(int i=0;i<m;i++){
    int a=bessi[i].first;
    for(int j=temp;j<=a;j++){
        b[j]=bessi[i].second;
    }
    temp=bessi[i].first+1;
}
//for(int i=0;i<101;i++)cout<<p[i]<<" ";cout<<endl;
//for(int i=0;i<101;i++)cout<<b[i]<<" ";cout<<endl;
int ans=0;
for(int i=1;i<=100;i++){
    //cout<<b[i]-p[i]<<endl;
    ans=max(ans,(b[i]-p[i]));
}



cout<<ans<<endl;




}//
























int main()
{
    startTime=(double)clock();
    freopen("speeding.in","r",stdin);
    freopen("speeding.out","w",stdout);
    //ioss
    //int t;cin>>t;while(t--)
    suraj();
    //suraj2();
    //suraj3();
    //suraj4();
    return 0;
}
