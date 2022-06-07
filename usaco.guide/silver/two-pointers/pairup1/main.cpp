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
int n;cin>>n;
vector<pair<ll,ll> >vp;
for(int i=0;i<n;i++){
  ll ta,tb;cin>>ta>>tb;
  vp.pb(make_pair(tb,ta));
}
sort(vp.begin(),vp.end());
int pl=0;int pr=n-1;
ll ans=0;
while(pl<=pr){
   // cout<<vp[pl].first<<" "<<vp[pl].second<<" "<<vp[pr].first<<" "<<vp[pr].second<<endl;
  if(pl==pr){
    if(vp[pl].second>=2){
      ans=max(ans,2*vp[pl].first);break;
    }else{
        break;
    }
  }
  ans=max(ans,vp[pr].first+vp[pl].first);
  if(vp[pr].second>vp[pl].second){
    vp[pr].second-=vp[pl].second;pl++;
  }else if(vp[pr].second<vp[pl].second){
    vp[pl].second-=vp[pr].second;pr--;
  }else{
    pr--;pl++;
  }
}
cout<<ans<<endl;


}//
























int main()
{
    startTime=(double)clock();
    freopen("pairup.in","r",stdin);
   freopen("pairup.out","w",stdout);
    ioss
    //int t;cin>>t;for(int i=1;i<=t;i++)//{cout<<"Case #"<<i<<": ";
    suraj();
    //}
    //suraj2();
    //suraj3();
    //suraj4();
    return 0;
}
