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
int n,m,d,s;
cin>>n>>m>>d>>s;
set<pair<int,pair<int,int>>>sp;
set<int>suspects,free;
for(int i=0;i<d;i++){
  int a,b,c;cin>>a>>b>>c;
      sp.insert(make_pair(a,make_pair(b,c)));
}
for(int i=0;i<s;i++){
    set<int>current;
    int a,b;cin>>a>>b;
    for(auto el:sp){
        if((el.first==a)&&((el.second).second<b)){
            suspects.insert(el.second.first);
            current.insert(el.second.first);
        }
    }
    for(int j=1;j<=m;j++){
        if((current.find(j)==current.end())){
            free.insert(j);
        }
    }

}
//for(int i:suspects)cout<<i<<" ";cout<<endl;for(int i:free)cout<<i<<" ";cout<<endl;
for(int i:suspects){
    if(free.find(i)!=free.end()){
        suspects.erase(i);
    }
}
//for(int i:suspects)cout<<i<<" ";cout<<endl;for(int i:free)cout<<i<<" ";cout<<endl;

int ans=0;
for(int i:suspects){
    set<int>sick;
    for(auto j:sp){
        if(j.second.first==i)sick.insert(j.first);
    }
    ans=max(ans,int(sick.size()));
}
cout<<ans<<endl;



}//
























int main()
{
    startTime=(double)clock();
    freopen("badmilk.in","r",stdin);
    freopen("badmilk.out","w",stdout);
    //ioss
    //int t;cin>>t;while(t--)
    suraj();
    //suraj2();
    //suraj3();
    //suraj4();
    return 0;
}
