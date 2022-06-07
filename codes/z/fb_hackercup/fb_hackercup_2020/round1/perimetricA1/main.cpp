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
























const ll mod=1e9+7;




void suraj(){

ll ans=1;
ll n,k,w;cin>>n>>k>>w;
vector<ll>l(k);for(ll &i:l)cin>>i;
ll al,bl,cl,dl;ll ah,bh,ch,dh;
cin>>al>>bl>>cl>>dl;
vector<ll>h(k);for(ll &i:h)cin>>i;
cin>>ah>>bh>>ch>>dh;
for(int i=k;i<n;i++){
    ll temp=al*l[i-2]+bl*l[i-1]+cl;
    temp=temp%dl;temp++;
    l.pb(temp);
}
for(int i=k;i<n;i++){
    ll temp=ah*h[i-2]+bh*h[i-1]+ch;
    temp=temp%dh;temp++;
    h.pb(temp);
}
cout<<"lets begin"<<endl;
for(int i=0;i<n;i++){
    cout<<"("<<l[i]<<","<<"0)"<<"&"<<"("<<l[i]+w<<","<<h[i]<<")"<<endl;
}
cout<<"lets end"<<endl;
//for(int i:l)cout<<i<<" ";cout<<endl;for(int i:h)cout<<i<<" ";cout<<endl;
//(l[i],0)&(l[i]+w,h[i])
vector<ll>p(n);
p[0]=w+w+h[0]+h[0];
//cout<<"w "<<w<<endl;
//cout<<"p[0] "<<p[0]<<endl;
ll x=l[0]+w;ll y=h[0];

vector<int>height(n);
set<int>s;
map<int,int>m;
s.insert(l[0]+w);m[l[0]+w]=h[0];
for(int i=1;i<n;i++){
    s.insert(l[i]+w);
    m[l[i]+w]=h[i];
    auto tt=s.lower_bound(l[i]);
    ll yy=m[*tt];
    if(l[i]>x){
        //cout<<"if"<<endl;
        //p[i]=p[i-1];
        p[i]=p[i-1]+2*(w+h[i]);
        x=l[i]+w;y=h[i];
    }else if(l[i]<x){
        //cout<<"else"<<endl;
        p[i]=p[i-1]+2*(l[i]+w-x);
        if(h[i]>yy){
            p[i]+=2*(h[i]-yy);
            y=h[i];
        }
        x=l[i]+w;
    }else if(l[i]==x){
        p[i]=p[i-1]+2*(l[i]+w-x);
        if(h[i]>y){
            p[i]+=2*(h[i]-y);
            y=h[i];
        }
        x=l[i]+w;
    }
    p[i]=p[i]%mod;
    //x=l[i]+w;
}
for(int i=0;i<n;i++){
    //cout<<"p["<<i<<"] "<<p[i]<<endl;
    //ans*=p[i];
    ans=((ans%mod)*(p[i]%mod))%mod;
}
cout<<ans%mod<<endl;
}//
























int main()
{
    startTime=(double)clock();
    //freopen("shell.in","r",stdin);
    //freopen("shell.out","w",stdout);
    ioss
    int t;cin>>t;
    for(int i=1;i<=t;i++){
        cout<<"Case #"<<i<<":"<<" ";
        suraj();
    }
    //suraj2();
    //suraj3();
    //suraj4();
    return 0;
}
