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


int n,q;cin>>n>>q;
//string forest[1000][1000];
vector<string>forest[n];
for(int i=0;i<n;i++){
    string a;cin>>a;
//    for(int j=0;j<a.size();j++){
//        forest[i][j]=a[j];
//    }
    forest[i].pb(a);
}

for(auto i:forest){
    for(auto j:i)cout<<j<<" ";cout<<endl;
}

//int arr[1001][1001]={0};
vector<int>arr[n+1];
vector<int>temp(n);
for(int i=0;i<=n;i++){
    arr[i]=temp;
}
for(auto i:arr){
    for(auto j:i)cout<<j<<" ";cout<<endl;
}
if(forest[0][0]=="*")arr[0][0]=1;
for(int i=1;i<n;i++){
    arr[0][i]=arr[0][i-1];
    if(forest[0][i]=="*")arr[0][i]++;
}
for(int i=1;i<n;i++){
    arr[i][0]=arr[i-1][0];
    if(forest[i][0]=="*")arr[i][0]++;
}
for(int i=1;i<n;i++){
    for(int j=1;j<n;j++){
        arr[i][j]=arr[i-1][j]+arr[i][j-1]-arr[i-1][j-1];
        if(forest[i][j]=="*")arr[i][j]++;
    }
}

for(int i=0;i<q;i++){
    int ya,xa,yb,xb;cin>>ya>>xa>>yb>>xb;
//    int ans=arr[yb][xb]-arr[ya][xb]-arr[yb][xa]+arr[ya][xa];
//    cout<<ans<<endl;
}






















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
