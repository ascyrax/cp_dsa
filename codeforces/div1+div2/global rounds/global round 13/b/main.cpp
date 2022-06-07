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
ll cost=0;
int n,ver,hor;cin>>n>>ver>>hor;

vector<int>col(n);for(int &i:col)cin>>i;
int zero=0,one=0,two=0;
for(int i=0;i<=n-2;i++){
    if(abs(col[i+1]-col[i])==0)zero++;
    if(abs(col[i+1]-col[i])==1)one++;
    if(abs(col[i+1]-col[i])>=2)two++;
}
ll hh=0,h=0,v=0,hv=0;
//we just need to bring 2horizzontal dist btwn two obstacles in differnt rows
hh=2*hor;
h=hor;
v=ver;
hv=hor+ver;
if(two>0)cout<<0<<endl;
else if(zero==n-1){
      cout<<min(hh,hv)<<endl;
}else{
      cout<<min(min(hh,h),v)<<endl;
}
//1 v-------always-(zero==n-1)
//2 h-------always
//1h 1v-----zero==n-1
//1h---------always-(zero==n-1)

















}//




































int main()
{
    startTime=(double)clock();
    //freopen("shell.in","r",stdin);freopen("shell.out","w",stdout);
    ioss
    int t;cin>>t;for(int i=1;i<=t;i++)//{cout<<"Case #"<<i<<": ";
    suraj();
    //}
    //suraj2();
    //suraj3();
    //suraj4();
    return 0;
}
