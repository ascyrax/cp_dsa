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
















//1    1
//2    8
//3    7
//4    4
//5    5
//6    6
//7    3
//8    2
//9    9

//1 2 3 4 5 6 7 8 9


void suraj(){

ll x;cin>>x;

if(x==1){
    cout<<"NO"<<endl;return;
}
int ans=0;
for(ll a=1;a<cbrt(x);a++){
    ll acube=a*a*a;
    ll bcube=x-acube;
    ll b=cbrt(bcube);
    if(b==0)continue;
    if(b*b*b==bcube){
        ans++;break;
    }
}
if(ans>0)cout<<"YES"<<endl;
else cout<<"NO"<<endl;






















}//




































int main()
{
    startTime=(double)clock();
    //freopen("shell.in","r",stdin);
    //freopen("shell.out","w",stdout);
    ioss
    int t;cin>>t;for(int i=1;i<=t;i++)//{cout<<"Case #"<<i<<": ";
    suraj();
    //}
    //suraj2();
    //suraj3();
    //suraj4();
    return 0;
}
