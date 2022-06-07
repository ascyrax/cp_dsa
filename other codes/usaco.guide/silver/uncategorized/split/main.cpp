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


















bool comp(pair<int,int>a,pair<int,int>b){
    if(a.second>b.second)return true;
    else return false;
}








void suraj(){



int n;cin>>n;
vector<pair<int,int>>vp(n),ta(n),tb(n);
for(auto &i:vp){
    cin>>i.first>>i.second;
}
ta=vp;tb=vp;
sort(ta.begin(),ta.end());
int xmin=ta[0].first;
int xmax=ta[n-1].first;


vector<int>vymax(n),vymin(n),tempmax(n),tempmin(n);//index i tak max y kitna hai
vymax[0]=ta[0].second;vymin[0]=ta[0].second;
for(int i=1;i<n;i++){
    vymax[i]=max(vymax[i-1],ta[i].second);
    vymin[i]=min(vymin[i-1],ta[i].second);
}
tempmax[n-1]=ta[n-1].second;
tempmin[n-1]=ta[n-1].second;
for(int i=n-2;i>=0;i--){
    tempmax[i]=max(tempmax[i+1],ta[i].second);
    tempmin[i]=min(tempmin[i+1],ta[i].second);
}
sort(tb.begin(),tb.end(),comp);
//for(auto i:ta)cout<<i.first<<" "<<i.second<<endl;
int ymax=tb[0].second;
int ymin=tb[n-1].second;

ll area1=abs(ll(ymax)-ll(ymin))*abs(ll(xmax)-ll(xmin));
ll area2=1e18;

int xa=ta[0].first,xb=0,xc=0,xd=ta[n-1].first;
//cout<<area1<<endl;
vector<ll>amin(n);
amin[n-1]=area1;
for(int i=n-2;i>=0;i--){
    vector<pair<int,int>>temp;
    xb=ta[i].first;
    xc=ta[i+1].first;
    int ymaxl=vymax[i];
    int yminl=vymin[i];
    ll areal=abs(ll(ymaxl)-ll(yminl))*abs(ll(xb)-ll(xa));
    ll arear=abs(ll(tempmax[i+1])-ll(tempmin[i+1]))*abs(ll(xd)-ll(xc));
    area2=min(area2,areal+arear);

}// till now we had done vertical sweep
//lets do horizontal sweep

vector<int>vymax(n),vymin(n),tempmax(n),tempmin(n);//index i tak max y kitna hai
vymax[0]=ta[0].second;vymin[0]=ta[0].second;
for(int i=1;i<n;i++){
    vymax[i]=max(vymax[i-1],ta[i].second);
    vymin[i]=min(vymin[i-1],ta[i].second);
}
tempmax[n-1]=ta[n-1].second;
tempmin[n-1]=ta[n-1].second;
for(int i=n-2;i>=0;i--){
    tempmax[i]=max(tempmax[i+1],ta[i].second);
    tempmin[i]=min(tempmin[i+1],ta[i].second);
}

cout<<area1-area2<<endl;




}//




































int main()
{
    startTime=(double)clock();
    freopen("split.in","r",stdin);
    freopen("split.out","w",stdout);
    ioss
    //int t;cin>>t;for(int i=1;i<=t;i++)//{cout<<"Case #"<<i<<": ";
    suraj();
    //}
    //suraj2();
    //suraj3();
    //suraj4();
    return 0;
}
