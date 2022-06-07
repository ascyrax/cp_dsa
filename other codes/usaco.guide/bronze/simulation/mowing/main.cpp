#include <bits/stdc++.h>
//#include <ext/pb_ds/assoc_container.hpp>

//using namespace __gnu_pbds;
using namespace std;

typedef  long long ll;
typedef long double ld;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

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
vector<pair<string,int>>v;
map<string,int>m;
for(int i=0;i<n;i++){
    string a;cin>>a;
    int b;cin>>b;
    v.pb(make_pair(a,b));
    m[a]+=b;
}
int vmax=0,hmax=0;
for(auto it=m.begin();it!=m.end();++it){
    if(it->first=="S"){
        vmax=max(vmax,it->second);
    }
    else if(it->first=="W")
        hmax=max(hmax,it->second);
}
int t=0;
int ans=10000;
map<pair<int,int>,int>f;
f[make_pair(hmax+5,vmax+5)]=t;
int x=hmax+5;int y=vmax+5;
for(int i=0;i<n;i++){
    cout<<"HI"<<endl;
    if(v[i].first=="N"){
        //cout<<"hi"<<endl;
        for(int j=1;j<=v[i].second;j++){
            if(f.find(make_pair(x,y+1))==f.end())
            f[make_pair(x,++y)]=++t;
            else{
                ans=min(ans,t+1-f[make_pair(x,++y)]);f[make_pair(x,y)]=++t;
            }
        }
    }
    else if(v[i].first=="S"){
        for(int j=1;j<=v[i].second;j++){
            if(f.find(make_pair(x,y-1))==f.end())
            f[make_pair(x,--y)]=++t;
            else{
                ans=min(ans,t+1-f[make_pair(x,--y)]);f[make_pair(x,y)]=++t;
            }
        }

    }
    else if(v[i].first=="E"){
        for(int j=1;j<=v[i].second;j++){
            if(f.find(make_pair(x,y+1))==f.end())
            f[make_pair(++x,y)]=++t;
            else{
                ans=min(ans,t+1-f[make_pair(++x,y)]);f[make_pair(x,y)]=++t;
            }
        }

    }
    else{
        for(int j=1;j<=v[i].second;j++){
            if(f.find(make_pair(x,y+1))==f.end())
            f[make_pair(--x,y)]=++t;
            else{
                ans=min(ans,t+1-f[make_pair(--x,y)]);f[make_pair(x,y)]=++t;
            }
        }

    }
}

cout<<ans<<endl;
}//
























int main()
{
    startTime=(double)clock();
    //freopen("shell.in","r",stdin);
    //freopen("shell.out","w",stdout);
    //ioss
    //int t;cin>>t;while(t--)
    suraj();
    //suraj2();
    //suraj3();
    //suraj4();
    return 0;
}
