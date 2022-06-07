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


int n;cin>>n;vector<int>v(n),vt;for(int &i:v)cin>>i;
vector<int>vPrefixSum;vPrefixSum.pb(0);/*vPrefixSum.pb(v[0]);*/
for(int i=0;i<n;i++){
    vPrefixSum.pb(v[i]+vPrefixSum[i]);
}
//for(int i:vPrefixSum)cout<<i<<" ";cout<<endl;
int ans=n;
int flag=-1;
for(int i=2;i<=n;i++){
    for(int j=0;j<=n-i;j++){
        int avg=vPrefixSum[j+i]-vPrefixSum[j];
        if(avg%i==0)avg/=i;
        else continue;

//        cout<<i<<" "<<j<<" "<<avg<<" "<<flag<<endl;

//        if(flag==0)continue;
//        else
//            avg/=i;
//        cout<<i<<" "<<j<<" "<<avg<<" "<<flag<<endl;
        for(int k=j;k<j+i;k++){
           if(v[k]==avg){ans++;break;}
        }
    }
}

cout<<ans<<endl;














}//




































int main()
{
    startTime=(double)clock();
//    freopen("shell.in","r",stdin);
//    freopen("shell.out","w",stdout);
    ioss
    //int t;cin>>t;for(int i=1;i<=t;i++)//{cout<<"Case #"<<i<<": ";
    suraj();
    //}
    //suraj2();
    //suraj3();
    //suraj4();
    return 0;
}
