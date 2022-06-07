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



int n;cin>>n;vector<int>v(n);for(int &i:v)cin>>i;
set<int>s;for(int i:v)s.insert(i);
if(s.size()>=2){
    cout<<("YES")<<endl;
}else {
    cout<<"NO"<<endl;return;
}
int ia=v[0];
vector<int>same;
for(int i=1;i<n;i++){
    if(v[i]==ia){
        same.pb(i);
    }
}
int tb=0;
for(int i=0;i<n;i++){
    if(v[i]!=ia){
        tb=i;break;
    }
}
vector<pair<int,int>>vp;
for(int i=0;i<n;i++){
    if(v[i]!=ia){
        vp.pb(make_pair(0,i));
    }
}
for(int i:same){
    vp.pb(make_pair(tb,i));
}
for(auto i:vp){
    cout<<i.first+1<<" "<<i.second+1<<endl;
}















}//




































int main()
{
    startTime=(double)clock();
    //freopen("shell.in","r",stdin);
    //freopen("shell.out","w",stdout);
    ioss
    int t;cin>>t;for(int i=1;i<=t;i++)//{cout<<"Case #"<<i<<": ";
    suraj();
    //}
    //suraj2();
    //suraj3();
    //suraj4();
    return 0;
}
