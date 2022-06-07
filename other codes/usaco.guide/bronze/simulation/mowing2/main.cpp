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
map<pair<int,int>,int>m;
/*for(int i=0;i<nn;i++){
    string a;cin>>a;int b;cin>>b;
    m[a]+=b;
}
int n=0,s=0,w=0,e=0;
for(auto it:m){
    if(it.first=="N")n+=it.second;
    else if(it.first=="S")s+=it.second;
    else if(it.first=="W")w+=it.second;
    else e+=it.second;
}
int x=w,y=s;
*/
int ans=500000;
int x=0,y=0;
int t=0;
m[make_pair(0,0)]=t;
for(int i=0;i<n;i++){
    string a;cin>>a;int b;cin>>b;
    for(int j=0;j<b;j++){
        if(a=="N"){
            if(m.find(make_pair(x,y+1))!=m.end()){
                ans=min(ans,t+1-(m[make_pair(x,y+1)]));
                m[make_pair(x,++y)]=++t;
            }else
            m[make_pair(x,++y)]=++t;
        }else if(a=="S"){
            if(m.find(make_pair(x,y-1))!=m.end()){
                ans=min(ans,t+1-(m[make_pair(x,y-1)]));
                m[make_pair(x,--y)]=++t;
            }else
            m[make_pair(x,--y)]=++t;
        }else if(a=="W"){
            if(m.find(make_pair(x-1,y))!=m.end()){
                ans=min(ans,t+1-(m[make_pair(x-1,y)]));
                m[make_pair(--x,y)]=++t;
            }else
            m[make_pair(--x,y)]=++t;
        }else{
            if(m.find(make_pair(x+1,y))!=m.end()){
                ans=min(ans,t+1-(m[make_pair(x+1,y)]));
                m[make_pair(++x,y)]=++t;
            }else
            m[make_pair(++x,y)]=++t;
        }
    }
}
cout<<ans<<endl;

}//
























int main()
{
    startTime=(double)clock();
    freopen("mowing.in","r",stdin);
    freopen("mowing.out","w",stdout);
    //ioss
    //int t;cin>>t;while(t--)
    suraj();
    //suraj2();
    //suraj3();
    //suraj4();
    return 0;
}
