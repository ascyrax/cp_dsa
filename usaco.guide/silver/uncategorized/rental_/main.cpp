/*
ID: ascyrax1
TASK: test
LANG: C++14
*/
/* LANG can be C++11 or C++14 for those more recent releases */
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
void suraj();
int main()
{
    startTime=(double)clock();
    //freopen("shell.in","r",stdin);freopen("shell.out","w",stdout);
    ioss
    //int t;cin>>t;for(int i=1;i<=t;i++)//{cout<<"Case #"<<i<<": ";
    suraj();
    //}
    //suraj2();
    //suraj3();
    //suraj4();
    return 0;
}




























bool custom(pair<ll,ll>a,pair<ll,ll>b){
    return a.second<b.second;
}







void suraj(){

ll n,m,r;cin>>n>>m>>r;
vector<ll>milk(n);for(ll &i:milk)cin>>i;
vector<pair<ll,ll>>qp(m);for(auto &i:qp)cin>>i.first>>i.second;
vector<ll>rent(r);for(ll &i:rent)cin>>i;
sort(milk.rbegin(),milk.rend());
sort(rent.rbegin(),rent.rend());
sort(qp.rbegin(),qp.rend());
ll sqp=0;
vector<ll>psmilk(n+1),psrent(r+1);
for(int i=1;i<=n;i++){
    psmilk[i]=psmilk[i-1]+milk[i-1];
    psrent[i]=psrent[i-1]+rent[i-1];
    sqp+=qp[i-1].first;
}
ll final=0;
for(ll i=0;i<n;i++){
    ll semi=0;
    ll sold=i;ll rented=n-i;
    if(rented>r||psmilk[sold]>sqp){
        continue;
    }else{
        semi+=psrent[rented];
        // milk to be sold=psmilk[sold]
        ll temp=psmilk[sold];
        ll cnt=0;
        while(temp>0){
            if(qp[cnt].first<=temp){
                temp-=qp[cnt].first;
                semi+=qp[cnt].first*qp[cnt].second;
                cnt++;
            }else{
                semi+=temp*qp[cnt].second;
                temp=0;cnt++;
            }
        }
    }
    cout<<semi<<endl;
    final=max(final,semi);
}

cout<<final<<endl;










}//
