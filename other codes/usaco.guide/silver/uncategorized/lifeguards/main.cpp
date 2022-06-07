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
vector<pair<int,int>>vp;
if(n==1)cout<<0<<endl;
for(int i=0;i<n;i++){
    int ta,tb;cin>>ta>>tb;
    vp.pb(make_pair(ta,tb));
}
sort(all(vp));
int tot=vp[0].second-vp[0].first;
vector<int>v(n);
for(int i=0;i<n;i++){
    //auto ta=vp[i];
    if(i>0){
        if(vp[i-1].second>=vp[i].second);
        else if(vp[i].first>=vp[i-1].second){
            tot=tot+vp[i].second-vp[i].first;
        }else{
            tot=tot+vp[i].second-vp[i-1].second;
        }
    }
    int ta=0;
    if(i-2>=0){
        if(vp[i-1].second<vp[i-2].second){
            vp[i-1].second=vp[i-2].second;
        }
    }
    if(i<n-1&&i>0){
        ta=min(vp[i].second,vp[i+1].first)-max(vp[i].first,vp[i-1].second);
    }else if(i==0&&i<n-1){
        ta=min(vp[i].second,vp[i+1].first)-vp[i].first;
    //}else if(i==0&&i>=n-1){
       // ta=vp[i].second-vp[i].first;
    }else if(i==n-1&&i>0){
        ta=vp[i].second-max(vp[i].first,vp[i-1].second);
    }
    int tb=vp[i].second-vp[i].first;
    int tl=0;int tr=0;
    if(i==0)tl=0;
    else{
        //auto tc=vp[i-1];
        tl=vp[i-1].second-vp[i].first;
        if(tl>0)tb-=tl;
    }
    if(i<n-1){
        if(vp[i+1].first<vp[i].second){
            tr=vp[i].second-vp[i+1].first;
        }tb-=tr;
    }else{
        tr=0;
    }
    if(tb<0)tb=0;
    v[i]=tb;
}
sort(all(v));
//cout<<tot<<endl;
//for(int i:v)cout<<i<<" ";cout<<endl;
cout<<tot-v[0]<<endl;

}//
























int main()
{
    startTime=(double)clock();
    freopen("lifeguards.in","r",stdin);
    freopen("lifeguards.out","w",stdout);
    ioss
    //int t;cin>>t;for(int i=1;i<=t;i++){cout<<"Case #"<<i<<": ";
    suraj();
    //}
    //suraj2();
    //suraj3();
    //suraj4();
    return 0;
}
