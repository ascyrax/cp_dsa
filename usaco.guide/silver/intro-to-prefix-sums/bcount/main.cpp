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
int n,q;cin>>n>>q;
vector<int>v(n);for(int &i:v)cin>>i;
vector<array<int,3>>a;
int ta=0,tb=0,tc=0;
a.pb({0,0,0});
for(int i=0;i<n;i++){
    if(v[i]==1)ta++;
    else if(v[i]==2)tb++;
    else tc++;
    array<int,3>td={ta,tb,tc};
    a.pb(td);
}
for(int i=0;i<q;i++){
    cin>>ta>>tb;ta--;
    cout<<a[tb][0]-a[ta][0]<<" "<<a[tb][1]-a[ta][1]<<" "<<a[tb][2]-a[ta][2]<<endl;
}




}//
























int main()
{
    startTime=(double)clock();
    freopen("bcount.in","r",stdin);
    freopen("bcount.out","w",stdout);
    ioss
    //int t;cin>>t;for(int i=1;i<=t;i++)//{cout<<"Case #"<<i<<": ";
    suraj();
    //}
    //suraj2();
    //suraj3();
    //suraj4();
    return 0;
}
