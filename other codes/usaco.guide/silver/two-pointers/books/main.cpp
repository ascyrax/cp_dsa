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
int n,t;cin>>n>>t;
vector<int>v(n);for(int &i:v)cin>>i;
vector<int>prefix_sum(n+1);
prefix_sum[1]=v[0];
for(int i=2;i<=n;i++){
    prefix_sum[i]=prefix_sum[i-1]+v[i-1];
}
//cout<<prefix_sum[3]<<endl;
int pl=0,pr=1;
int mx_ans=0;
int sa_sum=0;
while(pl<=n){
    sa_sum=prefix_sum[pr]-prefix_sum[pl];
    //cout<<sa_sum<<" "<<pl<<" "<<pr<<endl;
    if(sa_sum<=t){
        mx_ans=max(mx_ans,pr-pl);
        if(pr+1<=n)pr++;
        else{
            pl++;
        }
    }else{
        pl++;
    }
}

cout<<mx_ans<<endl;

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
