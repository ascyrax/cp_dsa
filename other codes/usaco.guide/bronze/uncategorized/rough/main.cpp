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

set<int>sa,sb;
vector<int>va,vb;
sa.insert(1);sa.insert(2);sa.insert(3);
sa.insert(1);sa.insert(3);sa.insert(2);
if(sa==sb)cout<<"sets are weird"<<endl;
va.pb(1);va.pb(2);va.pb(3);
va.pb(1);va.pb(3);va.pb(2);
if(va==vb)cout<<"vectors are weird"<<endl;

cout<<"ehy not me"<<endl;





















}//




































int main()
{
    startTime=(double)clock();
    //freopen("shell.in","r",stdin);
    //freopen("shell.out","w",stdout);
    ioss
    //int t;cin>>t;for(int i=1;i<=t;i++)//{cout<<"Case #"<<i<<": ";
    suraj();
    //}
    //suraj2();
    //suraj3();
    //suraj4();
    return 0;
}
