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






















//5
//3 1 9 2 7




void suraj(){




ll n;cin>>n;vector<ll>v(n),ps(n+1),smallest(n+1),temp(n+1);for(ll &i:v)cin>>i;

smallest[n]=v[n-1];
for(ll i=n-1;i>=1;i--){
    ps[i]=ps[i+1]+v[i];
    smallest[i]=min(smallest[i+1],v[i]);
}
vector<ll>ans;
ll maxavg=0;
for(ll i=n-2;i>=1;i--){
    ll avg=(ps[i]-smallest[i])/(n-i-1);//cout<<i<<" "<<avg<<" "<<endl;
    if(avg>maxavg){
        ans.clear();
        ans.pb(i);
    }else if(avg==maxavg){
        ans.pb(i);
    }//for(int i:ans)cout<<i<<" ";cout<<endl;
    maxavg=max(maxavg,avg);
}

sort(ans.begin(),ans.end());
for(ll i:ans)cout<<i<<endl;

















}//




































int main()
{
    startTime=(double)clock();
    freopen("homework.in","r",stdin);
    freopen("homework.out","w",stdout);
    ioss
    //int t;cin>>t;for(int i=1;i<=t;i++)//{cout<<"Case #"<<i<<": ";
    suraj();
    //}
    //suraj2();
    //suraj3();
    //suraj4();
    return 0;
}
