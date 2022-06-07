/*
ID: ascyrax1
TASK: test
LANG: C++14
*/

#include <bits/stdc++.h>
using namespace std;

typedef  long long ll;
typedef long double ld;

#define sz(x) (int)(x).size()
#define endl "\n"
#define ioss ios::sync_with_stdio(false);cin.tie(0);
#define pb push_back

double startTime;
double gct()//get_current_time
{
    return ((double)clock()-startTime)/CLOCKS_PER_SEC;
}
void suraj();





















vector<int,pair<int,int>>adjList(10000000);
vector<bool>visited(10000000);
void dfs(int node){
    if(visited[node])
        return;
    else
        visited[node]=true;
    for(auto neighbor:adjList[node]){
        dfs(neighbor);
    }return;
}












void suraj(){///////////////////////

int n,e;cin>>n>>e;
adjList.resize(n);
visited.resize(n);
for(int i=0;i<e;i++){
    int a,b;cin>>a>>b;
    int weight;cin>>weight;
    adjList[a].pb(make_pair(b,weight));
    adjList[b].pb(make_pair(a,weight));
}

int components=0;

for(int i=0;i<n;i++){
    if(visited[i]){
        continue;
    }else{
        components++;
        dfs(i);
    }
}

if(components>=2){
    cout<<"NIL"<<endl;
}else{
    //
}












}////////////////////////////




























int main()
{
    startTime=(double)clock();
    //freopen("shell.in","r",stdin);freopen("shell.out","w",stdout);
    ioss
    int t;cin>>t;for(int i=1;i<=t;i++)//{cout<<"Case #"<<i<<": ";
    suraj();
    //}
    return 0;
}
