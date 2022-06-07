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




















int n;
vector<vector<int>>tree(200000);
vector<int>vsub(200000);



int dfs(int node){
    int nsub=0;
    for(int neigh:tree[node]){
//        if(neigh<node)continue;
        nsub++;
        nsub+=dfs(neigh);
    }
    vsub[node]=nsub;
    return nsub;
}









void suraj(){///////////////////////

cin>>n;
tree.resize(n);
vsub.resize(n);
for(int i=1;i<=n-1;i++){
    int a;cin>>a;
//    tree[i].pb(a-1);
    tree[a-1].pb(i);
}
//cout<<"a"<<endl;
//for(int i=0;i<n;i++){
//    for(auto j:tree[i]){
//        cout<<j<<" ";
//    }cout<<endl;
//}

dfs(0);
for(int i=0;i<n;i++)
    cout<<vsub[i]<<" ";
cout<<endl;









}////////////////////////////




























int main()
{
    startTime=(double)clock();
    //freopen("shell.in","r",stdin);freopen("shell.out","w",stdout);
    ioss
    //int t;cin>>t;for(int i=1;i<=t;i++)//{cout<<"Case #"<<i<<": ";
    suraj();
    //}
    return 0;
}
