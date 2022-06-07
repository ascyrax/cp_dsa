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




























vector<bool>visited(100000);
vector<vector<int>>adj_list(100000);
vector<int>x(100000),y(100000);
int xa=1e9,ya=1e9,xb=0,yb=0;
void dfs(int node){
    for(auto neigh:adj_list[node]){
        if(visited[neigh]==1)continue;
        else{
            xa=min(xa,x[neigh]);ya=min(ya,y[neigh]);
            xb=max(xb,x[neigh]);yb=max(yb,y[neigh]);
//            cout<<xa<<" "<<ya<<" "<<xb<<" "<<yb<<endl;
            visited[neigh]=1;
            dfs(neigh);
        }
    }return;
}



void suraj(){///////////////////////

int n,m;cin>>n>>m;
visited.resize(n);
adj_list.resize(n);
x.resize(n);y.resize(n);
for(int i=0;i<n;i++){
    cin>>x[i]>>y[i];
}
for(int i=0;i<m;i++){
    int a,b;cin>>a>>b;
    adj_list[a-1].pb(b-1);
    adj_list[b-1].pb(a-1);
}

//for(int i=0;i<n;i++){
//    for(int j:adj_list[i])cout<<j+1<<" ";cout<<endl;
//}



int ans=1e9;
for(int i=0;i<n;i++){
//    for(int i=0;i<n;i++)cout<<visited[i]<<" ";cout<<endl;
    if(visited[i]==1){
//        cout<<"if"<<endl;
        continue;
    }else{
//        cout<<"else"<<endl;
        dfs(i);
        int perimeter=2*(xb-xa)+2*(yb-ya);//cout<<perimeter<<endl;
        ans=min(ans,perimeter);
        xa=1e9,ya=1e9,xb=0,yb=0;
    }
}
cout<<ans<<endl;










}////////////////////////////




























int main()
{
    startTime=(double)clock();
    freopen("fenceplan.in","r",stdin);freopen("fenceplan.out","w",stdout);
    ioss
    //int t;cin>>t;for(int i=1;i<=t;i++)//{cout<<"Case #"<<i<<": ";
    suraj();
    //}
    //suraj2();
    //suraj3();
    //suraj4();
    return 0;
}
