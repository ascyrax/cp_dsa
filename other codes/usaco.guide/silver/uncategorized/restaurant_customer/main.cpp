#include <bits/stdc++.h>
//#include <ext/pb_ds/assoc_container.hpp>

//using namespace __gnu_pbds;
using namespace std;

typedef  long long ll;
typedef long double ld;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

#define all(x) begin(x), end(x)
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
vector<int>a,b;
for(int i=0;i<n;i++){
    int ta,tb;cin>>ta>>tb;
    a.pb(ta);b.pb(tb);
}
sort(all(a));
sort(all(b));
int ans=0;
for(int i=0;i<n;i++){
    int tend=b[i];
    auto it=lower_bound(a.begin(),a.end(),tend)-a.begin()-(i);
    ans=max(ans,int(it));

}
cout<<ans<<endl;


}//
























int main()
{
    startTime=(double)clock();
    //freopen("shell.in","r",stdin);
    //freopen("shell.out","w",stdout);
    ioss
    //int t;cin>>t;for(int i=1;i<=t;i++){cout<<"Case #"<<i<<": ";
    suraj();
    //}
    //suraj2();
    //suraj3();
    //suraj4();
    return 0;
}