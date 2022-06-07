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






























int ncomps(void);
void dfs(int i);

int n,m,blocked[3005],tblocked[3005];
vector<int>adj_list[3005];




void suraj(){//////////////////////////
cin>>n>>m;
for(int i=0;i<m;i++){
    int a,b;cin>>a>>b;adj_list[a].pb(b);adj_list[b].pb(a);
}

if(ncomps()==1)cout<<"YES"<<endl;

for(int i=0;i<n;i++){
    int a;cin>>a;
    if(i==n-1)break;
    blocked[a]=1;
    if(ncomps()==1)cout<<"YES"<<endl;
    else cout<<"NO"<<endl;
}




}//////////////////////////








int ncomps(){
    int connected=0;
    for(int i=1;i<=n;i++){
        if(blocked[i]==1)continue;
        else if(tblocked[i]==1)continue;
        else{
            connected++;
            tblocked[i]=1;
            dfs(i);
        }
    }
    for(int j=0;j<3004;j++)tblocked[j]=0;
//    cout<<connected<<endl;
    return connected;
}


void dfs(int i){
    for(int j:adj_list[i]){
        if(blocked[j]==1)continue;
        if(tblocked[j]==1)continue;
        tblocked[j]=1;
        dfs(j);
    }return;
}
























int main()
{
    startTime=(double)clock();
    freopen("closing.in","r",stdin);freopen("closing.out","w",stdout);
    ioss
    //int t;cin>>t;for(int i=1;i<=t;i++)//{cout<<"Case #"<<i<<": ";
    suraj();
    //}
    //suraj2();
    //suraj3();
    //suraj4();
    return 0;
}
