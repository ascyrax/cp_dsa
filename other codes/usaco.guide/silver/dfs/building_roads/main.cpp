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






















void dfs(int i);








bool visited[100009];
vector<int>node[100009];
void suraj(){

int n,m;cin>>n>>m;


for(int i=0;i<m;i++){
    int a,b;cin>>a>>b;
    node[a].pb(b);
    node[b].pb(a);
}


map<int,int>newedge;
int ncomps=0;
for(int i=1;i<=n;i++){
    if(visited[i]==false){
        ncomps++;
        newedge[ncomps]=i;
        dfs(i);//
    }
}
cout<<ncomps-1<<endl;
for(int i=1;i<ncomps;i++){
    cout<<newedge[i]<<" "<<newedge[i+1]<<endl;
}






}//
void dfs(int i){
    for(int adjnode:node[i]){
        if(visited[adjnode]==false){
            visited[adjnode]=true;
            dfs(adjnode);
        }
    }return;
}






























int main()
{
    startTime=(double)clock();
    //freopen("shell.in","r",stdin);freopen("shell.out","w",stdout);
    ioss
    //int t;cin>>t;for(int i=1;i<=t;i++)//{cout<<"Case #"<<i<<": ";
    suraj();
    //}
    //suraj2();
    //suraj3();
    //suraj4();
    return 0;
}
