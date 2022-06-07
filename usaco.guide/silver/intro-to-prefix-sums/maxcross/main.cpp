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

int n,k,b;cin>>n>>k>>b;

vector<int>v(b);for(int &i:v)cin>>i;

sort(v.begin(),v.end());
vector<int> signals(n);
for(int i:v)signals[i-1]=1;

int l=0; int r=0+k;
vector<int>psum(n+1);
for(int i=1;i<=n;i++){
    psum[i]=psum[i-1]+signals[i-1];
}
int ans=n;
for(;r<=n;l++,r++){
    int broken=psum[r]-psum[l];
    ans=min(ans,broken);
}
cout<<ans<<endl;























}//




































int main()
{
    startTime=(double)clock();
    freopen("maxcross.in","r",stdin);
    freopen("maxcross.out","w",stdout);
    ioss
    //int t;cin>>t;for(int i=1;i<=t;i++)//{cout<<"Case #"<<i<<": ";
    suraj();
    //}
    //suraj2();
    //suraj3();
    //suraj4();
    return 0;
}
