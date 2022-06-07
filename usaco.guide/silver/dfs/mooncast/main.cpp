/*
ID: ascyrax1
TASK: test
LANG: C++14
*/
/* LANG can be C++11 or C++14 for those more recent releases */
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
void suraj();




















int n;
vector<int>adj_list[202];
vector<pair<pair<int,int>,int>>vp(202);
bool visited[202];


void dfs(int node){
    for(int j:adj_list[node]){
        if(visited[j]==true)continue;
        else{
            int p=vp[node].second;
            int dist=pow(vp[node].first.first-vp[j].first.first,2)+pow(vp[node].first.second-vp[j].first.second,2);
            if(dist<=p*p){
                visited[j]=true;//cout<<"node "<<node<<" dist "<<dist<<" power "<<p<<endl;
                dfs(j);
            }
        }
    }return;
}









void suraj(){///////////////////////
int ans=0;
cin>>n;
adj_list->resize(n+1);
vp.resize(n+1);

for(int i=1;i<=n;i++){
    int x,y,p;cin>>x>>y>>p;
    vp[i]=make_pair(make_pair(x,y),p);
}

for(int i=1;i<=n;i++){
    for(int j=1;j<=n;j++){
        if(j==i)continue;
        else{
            adj_list[i].pb(j);
        }
    }
}


for(int i=1;i<=n;i++){
    dfs(i);
    int count=0;
    for(int j=1;j<=n;j++){//cout<<visited[i]<<" ";
        if(visited[j]==true){
            count++;visited[j]=false;
        }
    }//cout<<endl<<count<<endl;
    ans=max(ans,count);
}
cout<<ans+1<<endl;











}////////////////////////////




























int main()
{
    startTime=(double)clock();
    freopen("moocast.in","r",stdin);freopen("moocast.out","w",stdout);
    ioss
    //int t;cin>>t;for(int i=1;i<=t;i++)//{cout<<"Case #"<<i<<": ";
    suraj();
    //}
    //suraj2();
    //suraj3();
    //suraj4();
    return 0;
}
