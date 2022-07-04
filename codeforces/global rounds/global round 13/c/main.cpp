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
vector<ll>vs(n);for(ll &i:vs)cin>>i;
ll ans=0;

vector<ll>temp(n);

for(int i=0;i<n;i++){
    ll diff=(vs[i]-1-temp[i]);
    if(diff>0){//cout<<"a"<<endl;
        ans+=diff;
        temp[i]+=diff;
        for(int j=2;j<=vs[i];j++){
            if(i+j<n)
                temp[i+j]++;
            else break;
        }
    }else if(diff<=0){//cout<<"b"<<endl;
        if(i+1<n)
            temp[i+1]+=abs(diff);
        for(int j=2;j<=vs[i];j++){
            if(i+j<n)
                temp[i+j]++;
            else break;
        }
    }
//    for(int i:temp)cout<<i<<" ";cout<<endl;cout<<ans<<endl;
}

//for(int i:temp)cout<<i<<" ";cout<<endl;
cout<<ans<<endl;















}//




































int main()
{
    startTime=(double)clock();
    //freopen("shell.in","r",stdin);freopen("shell.out","w",stdout);
    ioss
    int t;cin>>t;for(int i=1;i<=t;i++)//{cout<<"Case #"<<i<<": ";
    suraj();
    //}
    //suraj2();
    //suraj3();
    //suraj4();
    return 0;
}
