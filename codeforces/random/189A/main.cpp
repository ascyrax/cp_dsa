#include <bits/stdc++.h>
//#include <ext/pb_ds/assoc_container.hpp>

//using namespace __gnu_pbds;
using namespace std;

typedef  long long ll;
typedef long double ld;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

#define all(x) begin(x), end(x)
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

int n,a,b,c;cin>>n>>a>>b>>c;
int na=0,nb=0,nc=0;
int ans=0;
for(int i=0;i<=n/a;i++){
    for(int j=0;j<=n/b;j++){
        int k=(n-a*i-b*j)/c;
        if(k<0)continue;
            if(a*i+b*j+c*k==n){
               // if(i+j+k==4666){
                 //   cout<<i<<" "<<j<<" "<<k<<endl;
                //}
                ans=max(ans,i+j+k);
            }
    }
}


cout<<ans<<endl;

}//
























int main()
{
    startTime=(double)clock();
    //freopen("shell.in","r",stdin);
    //freopen("shell.out","w",stdout);
    //ioss
    //int t;cin>>t;while(t--)
    suraj();
    //suraj2();
    //suraj3();
    //suraj4();
    return 0;
}
