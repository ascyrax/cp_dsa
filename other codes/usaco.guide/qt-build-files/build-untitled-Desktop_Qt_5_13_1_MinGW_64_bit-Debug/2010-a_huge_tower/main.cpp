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














ll fact(ll ta){
    if(ta==0)return 1ll;
    return ta*fact(ta-1);
}














void suraj(){
int n;cin>>n;int d;cin>>d;vector<int>v(n);for(int &i:v)cin>>i;
sort(v.begin(),v.end());
vector<int>a;a.pb(-1);
for(int i=0;i<n-1;i++){
    if(v[i+1]-v[i]>d){
        a.pb(i);
    }
}a.pb(n-1);ll ans=1;
for(int i=1;i<a.size();i++){
    ll ta=a[i]-a[i-1];
    ans*=fact(ta);
}
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
