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

int n,k;cin>>n>>k;
vector<int>v(n);
for(int &i:v)cin>>i;
sort(v.begin(),v.end());
vector<int>a(n);
for(int i=0;i<n;i++){
    auto ta=v[i]+k;
    auto tb=upper_bound(v.begin(),v.end(),ta)-v.begin();
    auto tc=tb-i;
    a[i]=tc;
}
vector<int>b(n);
b[n-1]=a[n-1];
for(int i=n-2;i>=0;i--){
    b[i]=max(b[i+1],a[i]);
}
int ans=0;
for(int i=0;i<n-1;i++){
    auto ta=a[i];
    auto tb=i+ta;
    auto tc=0;
    if(i+ta<n)tc=b[i+ta];
    else continue;
    ans=max(ans,ta+tc);
}
cout<<ans<<endl;


}//
























int main()
{
    startTime=(double)clock();
    freopen("diamond.in","r",stdin);
    freopen("diamond.out","w",stdout);
    ioss
    //int t;cin>>t;for(int i=1;i<=t;i++)//{cout<<"Case #"<<i<<": ";
    suraj();
    //}
    //suraj2();
    //suraj3();
    //suraj4();
    return 0;
}
