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


int n,m;cin>>n>>m;
vector<int>cities(n),towers(m);
for(int &i:cities)cin>>i;for(int &i:towers)cin>>i;

//int pct=0,ptw=0;int ans=0;

//for(pct=0;pct<n;pct++){
//    int cityx=cities[pct];
//    int towerx=towers[ptw];
//    int dist=abs(cityx-towerx);
//    while(ptw<m-1&&abs(towers[ptw+1]-cities[pct])<=dist){
//        ptw++;dist=abs(towers[ptw]-cities[pct]);
//    }
//    ans=max(dist,ans);
//}

//cout<<ans<<endl;
int ans=0;
for(int i=0;i<n;i++){
    int dist=2e9;
    int right=lower_bound(towers.begin(),towers.end(),cities[i])-towers.begin();
    if(right<=m-1){
        dist=min(dist,towers[right]-cities[i]);
    }
    int left=right-1;
    if(left>=0){
        dist=min(dist,cities[i]-towers[left]);
    }


    ans=max(ans,dist);
}



cout<<ans<<endl;
















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
