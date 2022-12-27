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







// @author: ascyrax




























//...............................



void suraj(){

ll n,k;cin>>n>>k;
vector<ll>v(n);for(ll &i:v)cin>>i;
sort(v.begin(),v.end());


ll ml=0,mr=2e9+9;

while(ml+1<mr){
    ll mmid=ml+(mr-ml)/2;
    ll diff=0;
    for(ll i=n/2;i<n;i++){
        diff+=max(0ll,mmid-v[i]);
    }
//    cout<<ml<<" "<<mmid<<" "<<mr<<" "<<diff<<endl;
    if(diff<=k){
        ml=mmid;
    }else{
        mr=mmid-1;
    }
}
ll diff=0;
ll ans=0;
for(ll mmid=ml;mmid<=mr;mmid++){
    diff=0;
    for(ll i=n/2;i<n;i++){
        diff+=max(0ll,mmid-v[i]);
    }
    if(diff<=k){
        ans=max(ans,mmid);
    }
}

cout<<ans<<endl;











}


//................................




























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
