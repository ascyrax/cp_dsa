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
int sum=0;
int n,q;cin>>n>>q;
vector<int>vin(n);for(int &i:vin)cin>>i;
for(int i:vin)sum+=i;
for(int i=0;i<q;i++){
    int a,b;cin>>a>>b;
    if(a==1){
        if(vin[b-1]==0){
            sum++;vin[b-1]=1;
        }else if(vin[b-1]==1){
            sum--;vin[b-1]=0;
        }
    }else if(a==2){
        if(b<=sum)cout<<1<<endl;
        else cout<<0<<endl;
    }
}

























}//




































int main()
{
    startTime=(double)clock();
    //freopen("shell.in","r",stdin);freopen("shell.out","w",stdout);
    ioss
    //int t;cin>>t;for(int i=1;i<=t;i++)//{cout<<"Case #"<<i<<": ";
    suraj();
    //}
    //suraj2();
    //suraj3();
    //suraj4();
    return 0;
}
