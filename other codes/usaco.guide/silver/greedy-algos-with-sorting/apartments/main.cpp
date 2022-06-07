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




































void suraj(){///////////////////////


ll n,m,k;cin>>n>>m>>k;
vector<ll>applicants(n),apartments(m);
for(ll &i:applicants)cin>>i;
for(ll &i:apartments)cin>>i;
sort(applicants.begin(),applicants.end());
sort(apartments.begin(),apartments.end());
ll ans=0;
ll apart=0;
for(int appl=0;appl<n&&apart<m;appl++){
    if(abs(applicants[appl]-apartments[apart])<=k){
        ans++;
        apart++;
    }else if(applicants[appl]-apartments[apart]>k){
        appl--;
        apart++;
    }
}
cout<<ans<<endl;













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
