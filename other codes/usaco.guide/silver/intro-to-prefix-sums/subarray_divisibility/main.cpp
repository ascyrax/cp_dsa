#include <bits/stdc++.h>
//#include <ext/pb_ds/assoc_container.hpp>

//using namespace __gnu_pbds;
using namespace std;

typedef  long long ll;
typedef long double ld;
//mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

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



























void suraj(){



ll n;cin>>n;

vector<ll>v(n),ps(n+1);for(ll &i:v)cin>>i;

for(ll i=0;i<n;i++){
    ps[i+1]=ps[i]+v[i];
}
map<ll,ll>mp;
mp[0]=1;
ll ans=0;
for(ll i=1;i<=n;i++){
    ll rem=ps[i]%n;
    ll temp=0;
    if(rem>0)temp=rem-n;
    else temp=rem+n;
    ans+=mp[rem]+mp[temp];
    mp[(rem)]++;
}
cout<<ans<<endl;


//for(int i=0;i<n;i++){
//    mp[ps[i+1]%n]++;
//}

//for(auto i:mp){
////    cout<<i.first<<" "<<i.second<<endl;
//    ans+=(i.second*(i.second-1))/2;
//}
//cout<<ans<<endl;










}//




































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
