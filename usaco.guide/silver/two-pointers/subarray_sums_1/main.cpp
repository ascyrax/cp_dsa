#include <bits/stdc++.h>
//#include <ext/pb_ds/assoc_container.hpp>

//using namespace __gnu_pbds;
using namespace std;

typedef  long long ll;
typedef long double ld;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

#define all(x)  x.begin(),x.end()
#define rall(x) x.rbegin(),x.rend()
#define sz(x) (int)(x).size()
#define endl "\n"
#define ioss ios::sync_with_stdio(false);cin.tie(0);
#define pb push_back
#define eb emplace_back

double startTime;
double gct()//get_current_time
{
    return ((double)clock()-startTime)/CLOCKS_PER_SEC;
}





























void suraj2(){

int n,x;cin>>n>>x;
vector<ll>v(n),sum(n);for(ll &i:v)cin>>i;
sum[0]=v[0];
for(int i=1;i<n;i++){
    sum[i]=sum[i-1]+v[i];
}
int ans=0;
for(int i=0;i<n;i++){
    ll ta=sum[i];
    if(sum[i]<x)continue;
    ta=sum[i]-ll(x);
    if(ta==0){
        ans++;continue;
    }else if(ta>0){
        auto tb=lower_bound(sum.begin(),sum.begin()+i,ta);
        if(*tb==ta)ans++;
    }
}
cout<<ans<<endl;


}//




void suraj(){
//two pointer method
int n;cin>>n;
int x;cin>>x;
vector<ll>v(n),sa;for(auto &i:v)cin>>i;
sa.pb(0);
//sa[1]=v[0];
for(int i=0;i<n;i++){
    sa.pb(sa[i]+v[i]);
}
int l=1,r=1;
int ans=0;
int sum=0;
while(l<=r&&l<=n&&r<=n){
sum=sa[r]-sa[l-1];
//cout<<sum<<" "<<l<<" "<<r<<endl;
if(sum<x)r++;
else if(sum>x)l++;
else{
    ans++;l++;r++;
}
}
cout<<ans<<endl;
}












































int main()
{
    startTime=(double)clock();
    //freopen("shell.in","r",stdin);
    //freopen("shell.out","w",stdout);
    ioss
    //int t;cin>>t;for(int i=1;i<=t;i++)//{cout<<"Case #"<<i<<": ";
    suraj();
    //}
    //suraj2();
    //suraj3();
    //suraj4();
    return 0;
}
