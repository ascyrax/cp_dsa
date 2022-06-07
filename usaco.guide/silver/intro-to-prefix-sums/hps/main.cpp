#include <bits/stdc++.h>
//#include <ext/pb_ds/assoc_container.hpp>

//using namespace __gnu_pbds;
using namespace std;

typedef  long long ll;
typedef long double ld;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

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
int n;cin>>n;
vector<string>v(n);for(string &i:v)cin>>i;
int th=0,tp=0,ts=0;
vector<array<int,3>>left(n),right(n);
for(int i=0;i<n;i++){
    if(v[i]=="H")th++;
    else if(v[i]=="P")tp++;
    else ts++;
}
for(int i=0;i<1;i++){
left[i][0]=0;
left[i][1]=0;
left[i][2]=0;
right[i][0]=th;
right[i][1]=tp;
right[i][2]=ts;
if(v[i]=="H"){
    left[0][0]++;
    right[0][0]--;
}else if(v[i]=="P"){
    left[0][1]++;
    right[0][1]--;
}else{
    left[0][2]++;
    right[0][2]--;
}
}
for(int i=1;i<n;i++){
    int arr[3]={0,0,0};
    left[i][0]=left[i-1][0];
    left[i][1]=left[i-1][1];
    left[i][2]=left[i-1][2];
    right[i][0]=right[i-1][0];
    right[i][1]=right[i-1][1];
    right[i][2]=right[i-1][2];
    if(v[i]=="H"){
        th++;
        left[i][0]++;
        right[i][0]--;
    }else if(v[i]=="P"){
        tp++;
        left[i][1]++;
        right[i][1]--;
    }else if(v[i]=="S"){
        ts++;
        left[i][2]++;
        right[i][2]--;
    }
}
int ans=0;
for(int i=0;i<n;i++){
    int tx=0;
    int ty=max(max(left[i][0],left[i][1]),left[i][2]);
    int tz=max(max(right[i][0],right[i][1]),right[i][2]);
    ans=max(ans,ty+tz);
}
cout<<ans<<endl;




}//
























int main()
{
    startTime=(double)clock();
    freopen("hps.in","r",stdin);
    freopen("hps.out","w",stdout);
    ioss
    //int t;cin>>t;for(int i=1;i<=t;i++)//{cout<<"Case #"<<i<<": ";
    suraj();
    //}
    //suraj2();
    //suraj3();
    //suraj4();
    return 0;
}
