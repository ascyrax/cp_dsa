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
























int arr[1001][1001],tempr[1001][1001],tempb[1001][1001],temp[1001][1001];


void suraj(){



int n,k;cin>>n>>k;
vector<pair<int,int>>tl,br;
for(int i=0;i<n;i++){
    int xa,ya,xb,yb;cin>>xa>>ya>>xb>>yb;
    tl.pb(make_pair(xa,yb));br.pb(make_pair(xb,ya));
}

for(int i=0;i<n;i++){
    arr[tl[i].first][tl[i].second]+=1;
    tempr[br[i].first][tl[i].second+1]-=1;
    tempb[tl[i].first+1][br[i].second]-=1;
    temp[br[i].first+1][br[i].second+1]+=1;
}

for(int i=1;i<=1000;i++){
    for(int j=0;j<=1000;j++){
        arr[i][j]+=arr[i][j-1];
        tempr[i][j]+=tempr[i][j-1];
        tempb[i][j]+=tempb[i][j-1];
        temp[i][j]+=temp[i][j-1];
    }
}

for(int i=0;i<=1000;i++){
    for(int j=0;j<=1000;j++){
        arr[i][j]+=tempr[i][j]+tempb[i][j]+temp[i][j];
        arr[i][j]=max(0,arr[i][j]);
    }

}
int ans=0;
for(int i=0;i<=1000;i++){
    for(int j=0;j<=1000;j++){
        if(arr[i][j]==k)ans++;
    }
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
