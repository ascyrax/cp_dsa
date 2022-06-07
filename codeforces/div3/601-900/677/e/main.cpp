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


















ll pnc(ll n){
 ll ret=1;
 for(ll i=n;i>n/2;i--){
     ret*=i;
 }
 for(ll i=1;i<=n/2;i++){
     ret/=i;
 }
 return ret;
}


ll fact(ll n){
    if(n==0ll)return 1;
    else return n*fact(n-1);
}





void suraj(){



ll n;cin>>n;
ll ans=0;

ans+=pnc(n)/2;
//cout<<ans<<endl;
ans*=fact(n/2-1)*fact(n/2-1);











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
