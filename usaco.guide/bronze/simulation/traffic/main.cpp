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
string s,prs;int a,b,pra,prb;
vector<pair<string,pair<int,int>>>vp;
int a1,b1,an,bn;
for(int i=0;i<n;i++){
    cin>>s>>a>>b;
    vp.pb(make_pair(s,make_pair(a,b)));
}
//for(auto i:vp){
//    cout<<i.first<<" "<<i.second.first<<" "<<i.second.second<<endl;
//}
vector<int>vind,vindfinal;
for(int i=0;i<n;i++){
    if(vp[i].first=="none"){
        vind.pb(i);
    }
}
//for(int i:vind)cout<<i<<" ";cout<<endl;
for(int i=0;i<int(vind.size())-1;i++){
    if(vind[i+1]==vind[i]+1){
        vindfinal.pb(vind[i]);
    }else{
        vindfinal.pb(vind[i]);break;
    }
}
if(vind[vind.size()-1]==vind[vind.size()-2]+1)vindfinal.pb(vind[vind.size()-1]);
//for(int i:vindfinal)cout<<i<<" ";cout<<endl;
a1=vp[vindfinal[0]].second.first;
b1=vp[vindfinal[0]].second.second;
//cout<<a1<<" "<<b1<<endl;
for(int i=0;i<int(vindfinal.size());i++){
//    cout<<a1<<" "<<b1<<endl;
    a1=max(a1,vp[vindfinal[i]].second.first);
    b1=min(b1,vp[vindfinal[i]].second.second);
}
an=a1;bn=b1;
for(int i=vindfinal[0]-1;i>=0;i--){
    if(vp[i].first=="on"){
        a1-=vp[i].second.second;
        b1-=vp[i].second.first;
    }else if(vp[i].first=="off"){
        a1+=vp[i].second.first;
        b1+=vp[i].second.second;
    }
}
cout<<max(0,a1)<<" "<<max(0,b1)<<endl;

for(int i=vindfinal[vindfinal.size()-1];i<n;i++){
    if(vp[i].first=="on"){
        an+=vp[i].second.first;
        bn+=vp[i].second.second;
    }else if(vp[i].first=="off"){
        an-=vp[i].second.second;
        bn-=vp[i].second.first;
    }else{
        an=max(an,vp[i].second.first);
        bn=min(bn,vp[i].second.second);
    }
}
cout<<max(0,an)<<" "<<max(0,bn)<<endl;


















}//




































int main()
{
    startTime=(double)clock();
    freopen("traffic.in","r",stdin);
    freopen("traffic.out","w",stdout);
    ioss
    //int t;cin>>t;for(int i=1;i<=t;i++)//{cout<<"Case #"<<i<<": ";
    suraj();
    //}
    //suraj2();
    //suraj3();
    //suraj4();
    return 0;
}
