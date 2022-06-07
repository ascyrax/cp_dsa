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

































int n,m;
vector<vector<int>>graph(100000);
int ans=0;
vector<bool>visited(100000);
vector<char>color(100000);// blue and red




void dfs(int node,char c){//cout<<node<<" "<<c<<endl;
    if(visited[node]){//cout<<"if"<<endl;
        if(color[node]!=c){
            ans=-1;
            return;
        }else
            return;
    }else{//cout<<"else"<<endl;
        visited[node]=true;
        color[node]=c;
    }
    //now change the color for its neigbours
    if(c=='b')
        c='r';
    else c='b';
    for(int neigh:graph[node]){//cout<<"neigh "<<neigh<<endl;
        if(ans==-1)return;
        dfs(neigh,c);
    }return;
}






void suraj(){///////////////////////
cin>>n>>m;
graph.resize(n);visited.resize(n);color.resize(n);
//cout<<"here"<<endl;
for(int i=0;i<m;i++){
    int a,b;cin>>a>>b;
    graph[a-1].pb(b-1);
    graph[b-1].pb(a-1);

}
//for(auto i:graph){
//    for(auto j:i)cout<<j<<" ";cout<<endl;
//}
for(int i=0;i<n&&ans!=-1;i++){
//    cout<<"i "<<i<<endl;
    if(!visited[i])
    dfs(i,'b');
}

if(ans==-1){
    cout<<"IMPOSSIBLE"<<endl;
}else{
    for(int i=0;i<n;i++){
        if(color[i]=='b')
            cout<<1<<" ";
        else cout<<2<<" ";
    }cout<<endl;
}











}////////////////////////////




























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
