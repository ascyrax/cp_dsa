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



int n,x;cin>>n>>x;
vector<ll>v(n),ps(n+1);
for(int i=0;i<n;i++){
    int a;cin>>a;
    v[i]=a;
    ps[i+1]=ps[i]+a;
}

ll ans=0;
map<ll,vector<ll>>psind;
psind[0].pb(0);
for(int i=1;i<=n;i++){
    ll currentps=ps[i];
    ll pstofind=currentps-x;
    ans+=psind[pstofind].size();
    psind[ps[i]].pb(i);
}



//for(int i=1;i<=n;i++){
//    ll num=lower_bound(indices.begin(),indices.end(),i)-indices.begin();
//    ans+=num;
//}






cout<<ans<<endl;












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
