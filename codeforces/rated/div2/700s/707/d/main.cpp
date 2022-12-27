/*
ID: ascyrax1
TASK: test
LANG: C++14
*/

#include <bits/stdc++.h>
using namespace std;

typedef  long long ll;
typedef long double ld;

#define sz(x) (int)(x).size()
#define endl "\n"
#define ioss ios::sync_with_stdio(false);cin.tie(0);
#define pb push_back

double startTime;
double gct()//get_current_time
{
    return ((double)clock()-startTime)/CLOCKS_PER_SEC;
}
void suraj();



























ll func_hcf(ll n,ll m){
    if(n==0)return m;
    return func_hcf(m%n,n);
}








void suraj(){///////////////////////
ll n,m,k;cin>>n>>m>>k;

vector<ll>vn(n),vm(m);
for(ll &i:vn)cin>>i;
for(ll &i:vm)cin>>i;
if(n<m){
    ll temp=n;n=m;m=temp;//n >= m always
    auto vtemp=vn;vn=vm;vm=vtemp;
}
ll lcm=(m*n)/func_hcf(n,m);

ll mrecur=lcm/m;
for(ll i=0;i<m;i++){
    ll focus=vm[i];
}











}////////////////////////////




























int main()
{
    startTime=(double)clock();
    //freopen("shell.in","r",stdin);freopen("shell.out","w",stdout);
    ioss
    //int t;cin>>t;for(int i=1;i<=t;i++)//{cout<<"Case #"<<i<<": ";
    suraj();
    //}
    return 0;
}
