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

int n;cin>>n;
vector<ll>vstick_len(n);
for(ll &i:vstick_len)cin>>i;
sort(vstick_len.begin(),vstick_len.end());
ll median=0;
if(n%2==1)
    median=vstick_len[n/2];
else median=(vstick_len[n/2-1]+vstick_len[n/2])/2;
ll ans=0;
for(int i:vstick_len){
    ans+=abs(i-median);
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
