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





























void suraj(){

int n;cin>>n;
vector<int>v(n),ta(n);for(int &i:v)cin>>i;
ll sum=0;
vector<int>low(7,n+1),high(7);
//for(int i:low)cout<<i<<" ";cout<<endl;
for(int i=0;i<n;i++){
    sum+=v[i];
    int ta=sum%7;
    low[ta]=min(low[ta],i);
    high[ta]=max(high[ta],i);
}
//for(int i:high)cout<<i<<" ";cout<<endl;
//for(int i:low)cout<<i<<" ";cout<<endl;
int ans=0;
for(int i=0;i<=6;i++){
    ans=max(high[i]-low[i],ans);
}
cout<<ans<<endl;



}//
























int main()
{
    startTime=(double)clock();
    freopen("div7.in","r",stdin);
    freopen("div7.out","w",stdout);
    ioss
    //int t;cin>>t;for(int i=1;i<=t;i++)//{cout<<"Case #"<<i<<": ";
    suraj();
    //}
    //suraj2();
    //suraj3();
    //suraj4();
    return 0;
}
