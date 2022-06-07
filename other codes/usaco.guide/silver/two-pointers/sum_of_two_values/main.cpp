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
int n,x;cin>>n>>x;
vector<pair<int,int>>vp;
for(int i=1;i<=n;i++){
    int ta;cin>>ta;
    vp.pb(make_pair(ta,i));
}
sort(vp.begin(),vp.end());
int ta=0;int tb=n-1;
while(ta<tb){
    if(vp[ta].first+vp[tb].first<x){
        ta++;
    }else if(vp[ta].first+vp[tb].first>x){
        tb--;
    }else{
        cout<<vp[ta].second<<" "<<vp[tb].second<<endl;return;
    }
}

cout<<"IMPOSSIBLE"<<endl;



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
