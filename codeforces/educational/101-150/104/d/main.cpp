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


ll ans=0;

ll n;cin>>n;
for(ll i=3;i<=10;i++){
    ll sq=i*i;
    ll b=sq-1;
    ll c=sq+1;
    //cout<<sq<<" "<<b<<" "<<c<<endl;
    if(b%2==0){
        b/=2;
    }else{//cout<<"else 1"<<endl;
        continue;
    }
    if(c%2==0){
        c/=2;
    }else{
        continue;
    }
    if(c<=n)ans++;
    else break;

}

cout<<ans<<endl;




















}//




































int main()
{
    startTime=(double)clock();
    //freopen("shell.in","r",stdin);
    //freopen("shell.out","w",stdout);
    ioss
    int t;cin>>t;for(int i=1;i<=t;i++)//{cout<<"Case #"<<i<<": ";
    suraj();
    //}
    //suraj2();
    //suraj3();
    //suraj4();
    return 0;
}
