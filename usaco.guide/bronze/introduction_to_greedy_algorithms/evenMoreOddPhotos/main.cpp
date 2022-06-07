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

int n;cin>>n;
vector<int>v(n);for(int &i:v)cin>>i;
int even=0,odd=0;
for(int i:v){
    if(i%2==0)even++;
    else odd++;
}
if(even==odd)
    cout<<even+odd<<endl;
else if(even>odd)
    cout<<odd+odd+1<<endl;
else if(odd>even){
    int left=odd-even;
    int ans=even*2;
    while(left>=3){
        ans+=2;
        left-=3;
    }
    if(left==0)cout<<ans<<endl;
    else if(left==1){
        cout<<ans-1<<endl;
    }else if(left==2)
        cout<<ans+1<<endl;
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
